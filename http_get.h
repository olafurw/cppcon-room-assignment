#ifndef CPPCON_ROOM_ASSIGNMENT_HTTP_GET_H
#define CPPCON_ROOM_ASSIGNMENT_HTTP_GET_H

#include <string>
#include <optional>

typedef void CURL;

class HttpGet
{
public:
                                HttpGet();
                                ~HttpGet();

    std::optional<std::string>  Get(
                                    const std::string&  aUrl);

    void                        OnContent(
                                    std::string&&       aContent);
private:

    CURL*                       myCurl = nullptr;
    std::string                 myContent;
};

#endif
