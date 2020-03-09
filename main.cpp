/*
   Mathieu Stefani, 13 février 2016

   Example of an hello world server
*/
#include "HelloHandler.hpp"
#include <csignal>


  Pistache::Http::Endpoint *endpoint_p;


void shutdown_server(int no){
  endpoint_p->shutdown();
  std::cout << "\nShuting down server"<< std::endl;
  exit(no);
}

int main() {
  
  std::signal(SIGABRT,SIG_IGN);
  std::signal(SIGFPE,SIG_IGN);
  std::signal(SIGILL,SIG_IGN);
  std::signal(SIGSEGV,SIG_IGN);
  std::signal(SIGTERM,SIG_IGN);
  std::signal(SIGINT,shutdown_server);

  Pistache::Address addr("localhost", Pistache::Port(1234));
  auto router = std::make_shared<Pistache::Rest::Router>();    
  auto opts = Pistache::Http::Endpoint::options().threads(1); 
 
  Pistache::Http::Endpoint endpoint(addr);
  endpoint_p = &endpoint;
  endpoint.init(opts);

  auto hello_handler = HelloHandler();
  hello_handler.publish(router);
  endpoint.setHandler(router->handler());
  endpoint.serve();

}
