#pragma once

#include <pistache/endpoint.h>



class HelloHandler : public Pistache::Http::Handler {
public:

    HTTP_PROTOTYPE(HelloHandler)

    void onRequest(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter response) override;
};
