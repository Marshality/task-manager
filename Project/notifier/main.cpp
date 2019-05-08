#include <syslog.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <sys/stat.h>    //umask
#include <unistd.h>      //setsid
#include <stdio.h>       //perror
#include <signal.h>      //sidaction
#include <string.h>
#include <errno.h>
#include <sys/file.h>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>

#define LOCKFILE "/var/run/notifierd.pid"
#define LOCKMODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

class Notifier {
public:
    Notifier() = default;
    ~Notifier() = default;

    int alreadyRunning() {
        syslog(LOG_ERR, "Multiple running check.");

        int fd;
        char buf[16];

        fd = open(LOCKFILE, O_RDWR | O_CREAT, LOCKMODE);

        if (fd < 0) {
            syslog(LOG_ERR, "Can't open %s: %s.", LOCKFILE, strerror(errno));
            exit(1);
        }

        syslog(LOG_WARNING, "Lock-file is open.");

        flock(fd, LOCK_EX | LOCK_NB);

        if (errno == EWOULDBLOCK) {
            syslog(LOG_ERR, "Can't set block on %s: %s.", LOCKFILE, strerror(errno));
            close(fd);
            exit(1);
        }

        syslog(LOG_WARNING, "Writing: PID.");
        ftruncate(fd, 0);
        sprintf(buf, "%ld", (long) getpid());
        write(fd, buf, strlen(buf) + 1);
        syslog(LOG_WARNING, "Written: PID");

        return 0;
    }

    void daemonize(const char* cmd) {
        int fd0, fd1, fd2;
        pid_t pid;
        struct rlimit rl;
        struct sigaction sa;

        // 1. drop file creating mode mask
        umask(0);

        // 2. get max descriptor number to close others
        if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
            perror("Can't get max descriptor number.\n");
        }

        // 3. actions which guarantee that process is not group leader
        // required for setsid() call
        if ((pid = fork()) < 0) {
            perror("fork() error.\n");
        } else if (pid != 0) { // parent process
            exit(0);
        }

        // 4. daemon - leader of new session, leader of new group
        setsid();

        sa.sa_handler = SIG_IGN;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;

        if (sigaction(SIGHUP, &sa, NULL) < 0) {
            perror("SIGHUP can't be ignored.\n");
        }

        // 5. Set root directory as current work directory,
        // allows unmount file system
        if (chdir("/") < 0) {
            perror("Root directory can't be set as current work directory.\n");
        }

        // close all file descriptors
        if (rl.rlim_max == RLIM_INFINITY) {
            rl.rlim_max = 1024;
        }

        for (int i = 0; i < rl.rlim_max; i++) {
            close(i);
        }

        // 6. Connect file descriptors 0, 1, 2 to /dev/null
        fd0 = open("/dev/null", O_RDWR);
        fd1 = dup(0); // copy file descriptor
        fd2 = dup(0);

        // initialize journal file
        openlog(cmd, LOG_CONS, LOG_DAEMON);
        if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
            syslog(LOG_ERR, "False file descriptors %d %d %d\n", fd0, fd1, fd2);
            exit(1);
        }
        syslog(LOG_WARNING, "Daemon is running.");
    }

    bool check() {
        return false;
    }

    void notify() {

    }
};

int main(int argc, const char* argv[]) {
    Notifier notifier;

    notifier.daemonize("notifierd");

    if (notifier.alreadyRunning()) {
        syslog(LOG_ERR, "Notifier is already running.\n");
        exit(1);
    } else {
        syslog(LOG_WARNING, "Check is done.");
    }

    while (true) {
        if (notifier.check() != 0) {
            notifier.notify();
        }

        sleep(5);
    }
}