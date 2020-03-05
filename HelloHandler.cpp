#include "HelloHandler.hpp"

void HelloHandler::onRequest(const Http::Request& request, Http::ResponseWriter response){
  UNUSED(request);
  response.send(Pistache::Http::Code::Ok, "Hello World\n");
}
