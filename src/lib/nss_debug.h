#define _GNU_SOURCE
#include <stdio.h> // for asprintf
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <nss.h>
#include <sys/socket.h>
#include <unistd.h> // for isatty
#include <syslog.h>

void result(const char* , const char* );
extern char *__progname;
