#include "Service.h"
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8000

static void startup(Service *self) {
    puts("service started");
//    self->delegate->service(self->delegate->context, &(ServiceRequest){});
    int server_fd, new_socket;
    long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("In socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("In bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) {
        perror("In listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
            perror("In accept");
            exit(EXIT_FAILURE);
        }

        char buffer[30000] = {0};
        valread = read(new_socket, buffer, 30000);
        printf("%s\n", buffer);
        write(new_socket, hello, strlen(hello));
        printf("------------------Hello message sent-------------------\n");
        close(new_socket);
    }
}

// parse("GET /path/script.cgi?field1=value1&field2=value2 HTTP/1.1");
int parse(const char* line) {
    /* Find out where everything is */
    const char *start_of_path = strchr(line, ' ') + 1;
    const char *start_of_query = strchr(start_of_path, '?');
    const char *end_of_query = strchr(start_of_query, ' ');

    /* Get the right amount of memory */
    char path[start_of_query - start_of_path];
    char query[end_of_query - start_of_query];

    /* Copy the strings into our memory */
    strncpy(path, start_of_path,  start_of_query - start_of_path);
    strncpy(query, start_of_query, end_of_query - start_of_query);

    /* Null terminators (because strncpy does not provide them) */
    path[sizeof(path)] = 0;
    query[sizeof(query)] = 0;

    /*Print */
    printf("%s\n", query, sizeof(query));
    printf("%s\n", path, sizeof(path));
}

static void result(Service *self, ServiceRequest *request) {

}

static void fault(Service *self, ServiceRequest *request) {

}

static void init(Service *self) {
    self->startup = startup;
    self->result = result;
    self->fault = fault;
}

static Service *new() {
    Service *self = malloc(sizeof(Service));
    if (self == NULL) goto exception;
    init(self);
    return self;

    exception:
    fprintf(stderr, "Service allocation failed.\n");
    return NULL;
}

const struct $Service $Service = {.new = new};
