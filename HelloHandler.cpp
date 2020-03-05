#include "HelloHandler.hpp"

void HelloHandler::onRequest(const Http::Request& request, Http::ResponseWriter response){
  UNUSED(request);

  /* 
  std::vector<std::string> param = request.query().parameters(); 
   for (auto i: param){
   std::cout<<i<<std::endl;
   }
   
   std::cout<<request.body()<<std::endl;
    std::cout<<request.resource()<<std::endl;
  */

  //GET method
  if(request.method() == Http::Method::Get){
    if(request.resource() == "/welcome"){     
      response.send(Pistache::Http::Code::Ok, "Hello World!\n");
    }
    else{
      response.send(Pistache::Http::Code::No_Content);
    }
  }
  else{
    response.send(Pistache::Http::Code::No_Content);
  }
}
