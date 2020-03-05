/*
   Mathieu Stefani, 13 février 2016

   Example of an hello world server
*/
#include "HelloHandler.hpp"
int main() {


    Pistache::Address addr("localhost", Pistache::Port(1234));
    auto opts = Pistache::Http::Endpoint::options()
        .threads(1);

    Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(Http::make_handler<HelloHandler>());
    server.serve();
}
