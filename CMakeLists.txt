cmake_minimum_required(VERSION 3.21)
project(employee_admin C)

set(CMAKE_C_STANDARD 99)

set(SOURCES src/main.c src/model/request/Request.h src/model/request/Request.c src/model/request/Request.h)
list(APPEND SOURCES src/ApplicationFacade.c)
list(APPEND SOURCES src/controller/StartupCommand.c)
list(APPEND SOURCES src/controller/ServiceCommand.c)
list(APPEND SOURCES src/model/ServiceProxy.c)
list(APPEND SOURCES src/model/request/ServiceRequest.c)
list(APPEND SOURCES src/view/ServiceMediator.c)
list(APPEND SOURCES src/view/components/Service.c)
add_executable(employee_admin ${SOURCES})
target_link_libraries(employee_admin ${CMAKE_SOURCE_DIR}/lib/libPureMVC.a)
target_include_directories(employee_admin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/interfaces)

