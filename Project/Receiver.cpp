//
// Created by Marseille Gulaya on 2019-04-08.
//

#include "Receiver.h"

void Receiver::test(int arg) {
    invoker.setCommand(new ConcreteCommand(arg));
    invoker.execute();
}

void Receiver::createProject() {

}

void Receiver::deleteProject() {

}

void Receiver::createTask() {

}

void Receiver::deleteTask() {

}

void Receiver::editProject() {

}

void Receiver::editTask() {

}

void Receiver::assignUser() {

}
