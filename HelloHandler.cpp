#include "HelloHandler.hpp"

using namespace Pistache;

void HelloHandler::onRequest(const Http::Request& request,
			     Http::ResponseWriter response){
  std::string resource;
  std::string welcome_addr = "/welcome/";
  std::string message;

  //GET method
  if(request.method() == Http::Method::Get){
    resource = request.resource();
    if(resource == "/welcome"){
      if(request.query().as_str().empty()){ // only welcome addr but no parameters
	response.send(Pistache::Http::Code::Ok, "Hello World!\n");
      }
      else{ //only wlecome addr and parameters
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
    else if(!welcome_addr.compare(0,std::string::npos,resource,0,9)){//welcome addr and more
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
