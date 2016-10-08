#include "nss_debug.h"

#include <syslog.h>

void result(const char* function, const char* msg){
  static int i=0;
  if (isatty(fileno(stdin))){
    fprintf(stderr, "NSS DEBUG: function: %s, name: %s, i: %d\n", function, msg, i);
  }
  syslog (LOG_MAKEPRI(LOG_LOCAL1, LOG_INFO),"NSS DEBUG: function: %s, name: %s, i: %d\n", function, msg, i);
  i++;
}