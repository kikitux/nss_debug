#include "nss_debug.h"

enum nss_status _nss_last_sethostent(int stayopen) {
  char* c_stayopen;
  sprintf(c_stayopen, "%d", stayopen);
  result(__FUNCTION__,c_stayopen);
  return NSS_STATUS_SUCCESS;
}

enum nss_status _nss_last_endhostent(void) {
  result(__FUNCTION__,"");
  return NSS_STATUS_NOTFOUND;
}

enum nss_status _nss_last_gethostent_r(struct hostent *host, char *buffer,
                                        size_t buflen, int *errnop,
                                        int *h_errnop) {
  result(__FUNCTION__,host->h_addr_list[0]);
  return NSS_STATUS_NOTFOUND;
}

enum nss_status _nss_last_gethostbyaddr_r(const void *addr,
                                           socklen_t addrlen, int af,
                                           struct hostent *host,
                                           char *buffer, size_t buflen,
                                           int *errnop, int *h_errnop) {
  result(__FUNCTION__,inet_ntop(af, addr, buffer,buflen));
  return NSS_STATUS_NOTFOUND;
}

enum nss_status _nss_last_gethostbyname2_r(const char *name, int af,
                                            struct hostent *host,
                                            char *buffer, size_t buflen,
                                            int *errnop, int *h_errnop) {
  result(__FUNCTION__,name);
  return NSS_STATUS_NOTFOUND;
}

enum nss_status _nss_last_gethostbyname4_r(const char *name,
                                            struct gaih_addrtuple **pat,
                                            char *buffer, size_t buflen,
                                            int *errnop, int *h_errnop,
                                            int32_t *ttlp){
  result(__FUNCTION__,name);
  return NSS_STATUS_NOTFOUND;
}

enum nss_status _nss_last_gethostbyname_r(const char *name,
                                           struct hostent *host,
                                           char *buffer, size_t buflen,
                                           int *errnop, int *h_errnop) {
  result(__FUNCTION__,name);
  return NSS_STATUS_NOTFOUND;
}
