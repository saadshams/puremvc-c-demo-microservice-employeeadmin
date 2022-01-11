#ifndef EMPLOYEE_ADMIN_REQUEST_H
#define EMPLOYEE_ADMIN_REQUEST_H

typedef enum Method {UNSUPPORTED, GET, HEAD} Method;

typedef struct Header {
    char *name;
    char *value;
    struct Header *next;
} Header;

typedef struct Request {
    enum Method method;
    char *url;
    char *version;
    struct Header *headers;
    char *body;
} Request;


struct Request *parse_request(const char *raw);
void free_header(struct Header *h);
void free_request(struct Request *req);

// https://codereview.stackexchange.com/questions/188384/http-request-parser-in-c
// https://github.com/nodejs/llhttp

#endif //EMPLOYEE_ADMIN_REQUEST_H
