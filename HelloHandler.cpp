#include "HelloHandler.hpp"

using namespace Pistache;




void HelloHandler::publish(std::shared_ptr<Pistache::Rest::Router> router){
  using namespace Pistache::Rest;
  Routes::Get(*router, "/welcome", Routes::bind(&HelloHandler::printHelloWorld, this));
}

void HelloHandler::printHelloWorld(Pistache::Http::Request const&,Pistache::Http::ResponseWriter response){
  response.send(Pistache::Http::Code::Ok, "Hello World!\n");
}
