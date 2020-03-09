#pragma once

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>


class HelloHandler  {
public:

  void publish(std::shared_ptr<Pistache::Rest::Router> router); 
private:
  void printHelloWorld(Pistache::Http::Request const&,Pistache::Http::ResponseWriter response);
};

