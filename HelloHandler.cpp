#include "HelloHandler.hpp"

using namespace Pistache;




void HelloHandler::publish(std::shared_ptr<Pistache::Rest::Router> router){
  using namespace Pistache::Rest;
  Routes::Get(*router, "/welcome", Routes::bind(&HelloHandler::printHelloWorldAndParams, this));
  Routes::Get(*router, "/welcome/:addr", Routes::bind(&HelloHandler::printHelloAddr, this));
}

void HelloHandler::printHelloWorldAndParams(Pistache::Rest::Request const& request,Pistache::Http::ResponseWriter response){
  std::string message;
  if(request.query().as_str().empty()){ // only welcome addr but no parameters
    response.send(Pistache::Http::Code::Ok, "Hello World!\n");
  }
  else{
    message ="Hello";
    for(auto it = request.query().parameters_begin();
	it != request.query().parameters_end(); ++it){
      if(it->first == "name" || it->first == "surname")
	message += " " + it->second;
    }
    message += "!\n";	
    response.send(Pistache::Http::Code::Ok, message);
  }

}


void HelloHandler::printHelloAddr(Pistache::Rest::Request const& request,Pistache::Http::ResponseWriter response){
  response.send(Pistache::Http::Code::Ok, "Hello "+request.param(":addr").as<std::string>()+ "!\n");
}
