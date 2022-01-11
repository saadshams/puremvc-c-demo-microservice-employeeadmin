#ifndef EMPLOYEE_ADMIN_STARTUPCOMMAND_H
#define EMPLOYEE_ADMIN_STARTUPCOMMAND_H

#include "SimpleCommand.h"

struct $StartupCommand {
    SimpleCommand *(*new)();
};

const struct $StartupCommand $StartupCommand;

#endif //EMPLOYEE_ADMIN_STARTUPCOMMAND_H
