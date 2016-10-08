#include "nss_debug.h"
#include <stdio.h>
#include <netdb.h>
#include <memory.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

void udp(unsigned short port, char *message)
{
  struct sockaddr_in oAddr;
  socklen_t iAddrLen = sizeof(oAddr);
  memset((char *)&oAddr, 0,sizeof(oAddr));
  oAddr.sin_family      = AF_INET;
  oAddr.sin_port        = htons(port);
  oAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  int sock;
  if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
      return;
  }
  sendto(sock, message, strlen(message) + 1, MSG_CONFIRM, (struct sockaddr *)&oAddr, iAddrLen);
  close(sock);
  return;
}

void result(const char* function, const char* msg){

  char hostname[1024];
  hostname[1023] = '\0';
  gethostname(hostname, 1023);

  #if defined(LAST)
  char* NAME="LAST";
  #else
  char* NAME="DEBUG";
  #endif

  char* logmsg; // for the result message
  asprintf(&logmsg, "NSS %s: process: %s, function: %s, dst: %s, ppid: %d, pid: %d", NAME, __progname, function, msg, getppid(), getpid());

  char* metric; // for datadog
  asprintf(&metric, "sample.counter:1|c|#process:%s,function:%s,nss:%s,src:%s,dst:%s,ppid:%d,pid:%d", __progname, function, NAME, hostname, msg, getppid(), getpid());

  if (isatty(fileno(stdin))){
    fprintf(stderr, "%s\n", logmsg);
    fprintf(stderr, "%s\n", metric);
  }
  syslog (LOG_MAKEPRI(LOG_LOCAL1, LOG_INFO),"%s\n", logmsg);

  udp(8125, metric);
}
