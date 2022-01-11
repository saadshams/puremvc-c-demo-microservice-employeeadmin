#include "ServiceCommand.h"
#include <stdio.h>

static void execute(SimpleCommand *self, Notification *notification) {
    puts("service command");
}

static SimpleCommand *new() {
    SimpleCommand *self = $SimpleCommand.new();
    if (self == NULL) goto exception;
    self->execute = execute;
    return self;

    exception:
    fprintf(stderr, "ServiceCommand allocation failed.\n");
    return NULL;
}

const struct $ServiceCommand $ServiceCommand = {.new = new};