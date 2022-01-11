#include "ServiceMediator.h"
#include "Notifier.h"
#include "../ApplicationFacade.h"
#include "../model/request/ServiceRequest.h"
#include "components/Service.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void service(ServiceMediator *self, const void *data);

static void onRegister(Mediator *self) {
    Service *component = (Service *) self->viewComponent;
    component->delegate = &(Delegate) {self, (void (*)(const void *, const void *)) service};
    component->startup(component);
}

static void service(ServiceMediator *self, const void *data) {
    Notifier *notifier = self->mediator.notifier;
    Facade facade = ((ApplicationFacade *) (notifier->getFacade(notifier)))->facade;
    facade.sendNotification(&facade, SERVICE, &data, NULL);
}

static const char *const *listNotificationInterests(Mediator *self) {
    static const char *const interests[] = {SERVICE_RESULT, SERVICE_FAULT, NULL};
    return interests;
}

static void handleNotification(Mediator *self, Notification *notification) {
    Service *service = (Service *) self->viewComponent;
    ServiceRequest *request = (ServiceRequest *) notification->body;
    if (strcmp(notification->name, SERVICE_RESULT) == 0) {
        service->result(service, request);
    } else {
        service->fault(service, request);
    }
}

static ServiceMediator *new() {
    ServiceMediator *self = malloc(sizeof(ServiceMediator));
    if (self == NULL) goto exception;
    $Mediator.init(&self->mediator, "ServiceMediator", $Service.new());
    self->mediator.onRegister = onRegister;
    self->mediator.listNotificationInterests = listNotificationInterests;
    self->mediator.handleNotification = handleNotification;
    return self;

    exception:
    fprintf(stderr, "ServiceMediator allocation failed.\n");
    return NULL;
}

const struct $ServiceMediator $ServiceMediator = {.new = new};