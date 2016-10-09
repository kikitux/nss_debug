#include "nss_debug.h"

void udp(const unsigned short port, char* message)
{
  struct sockaddr_in oAddr;
  socklen_t iAddrLen = sizeof(oAddr);
  int sock;

  memset((char *)&oAddr, 0,sizeof(oAddr));
  oAddr.sin_family      = AF_INET;
  oAddr.sin_port        = htons(port);
  oAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
      return;
  }
  sendto(sock, message, strlen(message) + 1, MSG_CONFIRM, (struct sockaddr *)&oAddr, iAddrLen);
  close(sock);
  return;
}

void result(const char* function, const char* msg){

  char hostname[HOST_NAME_MAX]; // from limits.h
  hostname[HOST_NAME_MAX-1] = '\0';
  gethostname(hostname, HOST_NAME_MAX-1);

  #if defined(LAST)
  char* NAME="LAST";
  #else
  char* NAME="DEBUG";
  #endif

  char* logmsg; // for the result message
  asprintf(&logmsg,
           "NSS %s: command: %s, function: %s, dst: %s, ppid: %d",
           NAME, __progname, function, msg, getppid());

  char* metric; // for datadog
  asprintf(&metric,
           "sample.counter:1|c|#command:%s,function:%s,nss:%s,src:%s,dst:%s,ppid:%d",
           __progname, function, NAME, hostname, msg, getppid());

  if (isatty(fileno(stdin))){
    fprintf(stderr, "%s\n%s\n", logmsg, metric);
  }

  syslog (LOG_MAKEPRI(LOG_LOCAL1, LOG_INFO),"%s\n", logmsg);
  udp(8125, metric);
}
