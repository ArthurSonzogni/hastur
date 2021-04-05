#ifndef CAPI_CAPI_H_
#define CAPI_CAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

// http/get.h
struct HasturHttpResponse {
    const char *header;
    const char *body;
};

struct HasturHttpResponse hastur_http_get(const char *endpoint);
void hastur_http_kill(struct HasturHttpResponse *response);

#ifdef __cplusplus
}
#endif

#endif
