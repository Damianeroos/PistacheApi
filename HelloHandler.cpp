#include "HelloHandler.hpp"

using namespace Pistache;

void HelloHandler::onRequest(const Http::Request& request,
			     Http::ResponseWriter response){
  std::string resource;
  std::string welcome = "/welcome/";
  std::string message;
  //GET method
  if(request.method() == Http::Method::Get){
    resource = request.resource();
    if(resource == "/welcome"){      
      response.send(Pistache::Http::Code::Ok, "Hello World!\n");
    }
    else if(!welcome.compare(0,std::string::npos,resource,0,9)){
      response.send(Pistache::Http::Code::Ok, "Hello " + resource.substr(9) + "!\n");
    }
    else{
      response.send(Pistache::Http::Code::Bad_Request);
    }
  }
  else{
    response.send(Pistache::Http::Code::Bad_Request);
  }
  
  
}
//cos co wyświetli zmienna wysłana w formie adresu ...:9080/welcome/XXX ---> Hello XXX!
/// cos co wyświetli .../welcome?name=Damian&surname=Rakowski ---> Hello Damian Rakowski!
//jak wywołac shotdown nie znajac adrresu funckjii
//podmienic readme
