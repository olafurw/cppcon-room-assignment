#include "http_get.h"

#include <curl/curl.h>

HttpGet::HttpGet()
    : myCurl(curl_easy_init())
{
}

HttpGet::~HttpGet()
{
    if(myCurl)
    {
        curl_easy_cleanup(myCurl);
    }
}

void
HttpGet::OnContent(
    std::string&&   aContent)
{
    myContent += aContent;
}

static size_t
WriteMemoryCallback(
    void*       aContent,
    size_t      aSize,
    size_t      aNmemb,
    void*       aUserPointer)
{
    const size_t contentLength = aSize * aNmemb;
    std::string content(static_cast<char*>(aContent), contentLength);

    HttpGet* get = static_cast<HttpGet*>(aUserPointer);
    if (!get)
    {
        return 0;
    }

    get->OnContent(std::move(content));

    return contentLength;
}

std::optional<std::string>
HttpGet::Get(
    const std::string&  aUrl)
{
    myContent = "";

    curl_easy_setopt(myCurl, CURLOPT_USERAGENT, "cppcon/1.0");
    curl_easy_setopt(myCurl, CURLOPT_URL, aUrl.c_str());
    curl_easy_setopt(myCurl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(myCurl, CURLOPT_WRITEDATA, this);

    const CURLcode result = curl_easy_perform(myCurl);
    if (result != CURLE_OK)
    {
        return std::nullopt;
    }

    return myContent;
}
