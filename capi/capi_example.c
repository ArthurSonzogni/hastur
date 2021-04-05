#include "capi/capi.h"

#include <stdio.h>

int main() {
    struct HasturHttpResponse response = hastur_http_get("example.com");
    printf("%s\n\n", response.header);
    printf("%s\n\n", response.body);
    hastur_http_kill(&response);
}
