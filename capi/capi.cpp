#include "capi/capi.h"

#include "http/get.h"

#include <cstdlib>
#include <cstring>

namespace {

char *capi_strdup(const char *str) {
    size_t len = std::strlen(str) + 1;
    char *p = static_cast<char *>(std::malloc(len));
    return p ? static_cast<char *>(std::memcpy(p, str, len)) : NULL;
}

} // namespace

#ifdef __cplusplus
extern "C" {
#endif

// http/get.h
HasturHttpResponse hastur_http_get(const char *endpoint) {
    HasturHttpResponse c_response{};

    auto response = http::get(endpoint);
    if (!response.header.empty()) {
        c_response.header = capi_strdup(response.header.c_str());
    }

    if (!response.body.empty()) {
        c_response.body = capi_strdup(response.body.c_str());
    }

    return c_response;
}

void hastur_http_kill(struct HasturHttpResponse *response) {
    free(reinterpret_cast<void *>(const_cast<char *>(response->header)));
    free(reinterpret_cast<void *>(const_cast<char *>(response->body)));
}

#ifdef __cplusplus
}
#endif
