#ifndef EMPLOYEE_ADMIN_SERVICECOMMAND_H
#define EMPLOYEE_ADMIN_SERVICECOMMAND_H

#include "SimpleCommand.h"

struct $ServiceCommand {
    SimpleCommand *(*new)();
};

const struct $ServiceCommand $ServiceCommand;

#endif //EMPLOYEE_ADMIN_SERVICECOMMAND_H
