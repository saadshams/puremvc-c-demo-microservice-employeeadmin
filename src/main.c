#include "ApplicationFacade.h"

int main() {
    ApplicationFacade *facade = $ApplicationFacade.getInstance("employee_admin", $ApplicationFacade.new);
    facade->startup(facade);
    return 0;
}
