/*
   Mathieu Stefani, 13 février 2016

   Example of an hello world server
*/
#include "HelloHandler.hpp"
#include <csignal>


  Pistache::Http::Endpoint *server_p;


void shutdown_server(int no){
  server_p->shutdown();
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
  auto opts = Pistache::Http::Endpoint::options()
    .threads(1);

  Pistache::Http::Endpoint server(addr);

  server_p = &server;
  server.init(opts);
  server.setHandler(Pistache::Http::make_handler<HelloHandler>());
  server.serve();

}
