#include "http_init.h"

#include <curl/curl.h>

HttpInit::HttpInit()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

HttpInit::~HttpInit()
{
    curl_global_cleanup();
}