#include "ApplicationFacade.h"
#include "controller/StartupCommand.h"
#include <stdio.h>

static void initializeController(ApplicationFacade *self) {
    self->facade.initializeController(&self->facade);
    self->facade.registerCommand(&self->facade, STARTUP, $StartupCommand.new);
}

static void startup(ApplicationFacade *self) {
    self->facade.sendNotification(&self->facade, STARTUP, NULL, NULL);
}

static void init(ApplicationFacade *self) {
    $Facade.init(&self->facade);
    self->startup = startup;
    self->initializeController = initializeController;
}

static ApplicationFacade *new(const char *key) {
    ApplicationFacade *self = malloc(sizeof(ApplicationFacade));
    if (self == NULL) goto exception;
    init(self);
    self->facade.multitonKey = key;
    self->initializeController(self);
    return self;

    exception:
    fprintf(stderr, "ApplicationFacade allocation failed.\n");
    return NULL;
}

static ApplicationFacade *getInstance(const char *key, ApplicationFacade *(*factory)(const char *)) {
    return (ApplicationFacade *) $Facade.getInstance(key, (Facade *(*)(const char *)) factory);
}

const struct $ApplicationFacade $ApplicationFacade = {.new = new, .getInstance = getInstance};
