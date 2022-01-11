#ifndef EMPLOYEE_ADMIN_APPLICATION_FACADE_H
#define EMPLOYEE_ADMIN_APPLICATION_FACADE_H

#include "Facade.h"

#define STARTUP "Startup"
#define SERVICE "Service"
#define SERVICE_RESULT "ServiceResult"
#define SERVICE_FAULT "ServiceFault"

typedef struct ApplicationFacade ApplicationFacade;

struct ApplicationFacade {
    Facade facade;

    void (*initializeController)(ApplicationFacade *self);

    void (*startup)(ApplicationFacade *self);
};

struct $ApplicationFacade {
    ApplicationFacade *(*new)(const char *key);

    ApplicationFacade *(*getInstance)(const char *key, ApplicationFacade *(factory)(const char *));
};

const struct $ApplicationFacade $ApplicationFacade;

#endif //EMPLOYEE_ADMIN_APPLICATION_FACADE_H
