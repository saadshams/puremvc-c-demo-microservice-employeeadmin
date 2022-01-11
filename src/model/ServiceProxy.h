#ifndef EMPLOYEE_ADMIN_SERVICE_PROXY_H
#define EMPLOYEE_ADMIN_SERVICE_PROXY_H

#include "Proxy.h"

typedef struct ServiceProxy ServiceProxy;

struct ServiceProxy {
    Proxy proxy;
};

struct $ServiceProxy {
    ServiceProxy *(*new)(void);
};

const struct $ServiceProxy $ServiceProxy;

#endif //EMPLOYEE_ADMIN_SERVICE_PROXY_H
