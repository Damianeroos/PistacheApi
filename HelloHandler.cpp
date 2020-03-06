#include "HelloHandler.hpp"

using namespace Pistache;

void HelloHandler::onRequest(const Http::Request& request,
			     Http::ResponseWriter response){

  //GET method
  if(request.method() == Http::Method::Get &&
     request.resource() == "/welcome"){      
    response.send(Pistache::Http::Code::Ok, "Hello World!\n");
  
  }
  else{
    response.send(Pistache::Http::Code::Bad_Request);
  }
  
  
}
