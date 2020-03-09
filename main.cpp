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
  
  signal(SIGABRT,SIG_IGN);
  signal(SIGFPE,SIG_IGN);
  signal(SIGILL,SIG_IGN);
  signal(SIGSEGV,SIG_IGN);
  signal(SIGTERM,SIG_IGN);
  signal(SIGINT,shutdown_server);


  Pistache::Address addr("localhost", Pistache::Port(1234));
  auto opts = Pistache::Http::Endpoint::options()
    .threads(1);

  Pistache::Http::Endpoint server(addr);

  server_p = &server;
  server.init(opts);
  server.setHandler(Pistache::Http::make_handler<HelloHandler>());
  server.serveThreaded();
  std::cout<<"\nServer starts"<<std::endl;

   while(1) {
      sleep(1);
   }


}
