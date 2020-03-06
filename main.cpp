/*
   Mathieu Stefani, 13 février 2016

   Example of an hello world server
*/
#include "HelloHandler.hpp"
#include <signal.h>

int main() {
  sigset_t signals;
  if (sigemptyset(&signals) != 0
      || sigaddset(&signals, SIGTERM) != 0
      || sigaddset(&signals, SIGINT) != 0
      || sigaddset(&signals, SIGHUP) != 0
      || pthread_sigmask(SIG_BLOCK, &signals, nullptr) != 0) {
    perror("install signal handler failed");
    return 1;
  }

  Pistache::Address addr("localhost", Pistache::Port(9080));
  auto opts = Pistache::Http::Endpoint::options()
    .threads(1);

  Pistache::Http::Endpoint server(addr);
  server.init(opts);
  server.setHandler(Pistache::Http::make_handler<HelloHandler>());
  server.serveThreaded();

  int signal = 0;
  int status = sigwait(&signals, &signal);
  if (status == 0)
    {
      std::cout << "Shuting down server " << signal << std::endl;
      server.shutdown();
    }

}
