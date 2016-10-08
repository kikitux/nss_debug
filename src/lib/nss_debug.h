//#include "nss.h"
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <nss.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h> // for isatty

//void log(const char* function, const char* msg, const int i){
//  if (isatty(fileno(stdin))){
//    fprintf(stderr, "NSS DEBUG: function: %s, name: %s, i: %d\n", function, msg, i);
//  }
//}
