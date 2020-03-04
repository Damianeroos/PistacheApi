#include "hellohandler.hpp"


int main() {
  Http::listenAndServe<HelloHandler>("*:9080");
}


