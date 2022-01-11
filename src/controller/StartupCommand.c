#include "StartupCommand.h"
#include "ServiceCommand.h"
#include "Notifier.h"
#include "../ApplicationFacade.h"
#include "../model/ServiceProxy.h"
#include "../view//ServiceMediator.h"
#include <stdio.h>

static void execute(SimpleCommand *self, Notification *notification) {
    Facade *facade = self->notifier->getFacade(self->notifier);
    facade->registerCommand(facade, SERVICE, $ServiceCommand.new);
    facade->registerProxy(facade, (Proxy *) $ServiceProxy.new());
    facade->registerMediator(facade, (Mediator *) $ServiceMediator.new());
}

static SimpleCommand *new() {
    SimpleCommand *self = $SimpleCommand.new();
    if (self == NULL) goto exception;
    self->execute = execute;
    return self;

    exception:
    fprintf(stderr, "StartupCommand allocation failed.\n");
    return NULL;
}

const struct $StartupCommand $StartupCommand = {.new = new};