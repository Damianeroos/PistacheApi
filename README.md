Simple helloserver app that uses pistache library.

server addr: http://localhost:1234

supported requests:

GET {addr}/welcome				 ----> Hello wrold!

GET {addr}/welcome/{addr1}			 ----> Hello {addr1}!

GET {addr}/wlecome?name={name}&surname={surname} ----> Hello {surname} {name}!

To close appliation send signal SININT (press ctrl-C). Other signals are ignored.
Remember to type URL addr in quote, e.g.: curl -X GET "http://localhost:1234/welcome/XXX"