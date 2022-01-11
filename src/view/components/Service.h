#ifndef EMPLOYEE_ADMIN_SERVICE_H
#define EMPLOYEE_ADMIN_SERVICE_H

#include "../../model/request/ServiceRequest.h"

typedef struct Delegate Delegate;

struct Delegate {
    const void *context;
    void (*service)(const void *context, const void *data);
};

typedef struct Service Service;

struct Service {
    Delegate *delegate;
    void (*startup)(Service *self);
    void (*result)(Service *self, ServiceRequest *request);
    void (*fault)(Service *self, ServiceRequest *request);
};

struct $Service {
    Service *(*new)();
};

const struct $Service $Service;

#endif //EMPLOYEE_ADMIN_SERVICE_H
