#define _GNU_SOURCE
#include <arpa/inet.h>
#include <errno.h>
#include <limits.h> // for HOST_NAME_MAX
#include <memory.h>
#include <netdb.h>
#include <netinet/in.h>
#include <nss.h>
#include <stdio.h> // for asprintf
#include <syslog.h>
#include <sys/socket.h>
#include <unistd.h> // for isatty

void udp(const unsigned short , char*);
void result(const char* , const char* );
extern char *__progname;
