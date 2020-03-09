#include "HelloHandler.hpp"

using namespace Pistache;




void HelloHandler::publish(std::shared_ptr<Pistache::Rest::Router> router){
  using namespace Pistache::Rest;
  Routes::Get(*router, "/welcome", Routes::bind(&HelloHandler::printHelloWorld, this));
  Routes::Get(*router, "/welcome/*", Routes::bind(&HelloHandler::printHelloName, this));
  Routes::Get(*router, "/welcome/:addr", Routes::bind(&HelloHandler::printHelloAddr, this));
}

void HelloHandler::printHelloWorld(Pistache::Rest::Request const&,Pistache::Http::ResponseWriter response){
  response.send(Pistache::Http::Code::Ok, "Hello World!\n");
}

void HelloHandler::printHelloName(Pistache::Rest::Request const& ,Pistache::Http::ResponseWriter response){
  // response.send(Pistache::Http::Code::Ok, "Hello "+request.param(":addr").as<std::string>());
}

void HelloHandler::printHelloAddr(Pistache::Rest::Request const& request,Pistache::Http::ResponseWriter response){
  response.send(Pistache::Http::Code::Ok, "Hello "+request.param(":addr").as<std::string>()+ "!\n");
}
