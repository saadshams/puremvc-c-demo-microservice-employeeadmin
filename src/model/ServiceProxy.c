#include "ServiceProxy.h"
#include <stdio.h>

static ServiceProxy *new() {
    ServiceProxy *self = malloc(sizeof(ServiceProxy));
    if (self == NULL) goto exception;
    $Proxy.init(&self->proxy, "ServiceProxy", NULL);
    return self;

    exception:
    fprintf(stderr, "ServiceProxy allocation failed.\n");
    return NULL;
}

const struct $ServiceProxy $ServiceProxy = {.new = new};
