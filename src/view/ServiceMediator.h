#ifndef EMPLOYEE_ADMIN_SERVICE_MEDIATOR_H
#define EMPLOYEE_ADMIN_SERVICE_MEDIATOR_H

#include "Mediator.h"

typedef struct ServiceMediator ServiceMediator;

struct ServiceMediator {
    Mediator mediator;
};

struct $ServiceMediator {
    ServiceMediator *(*new)();
};

const struct $ServiceMediator $ServiceMediator;

#endif //EMPLOYEE_ADMIN_SERVICE_MEDIATOR_H
