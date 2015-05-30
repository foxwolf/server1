# Introduction #
The benchmark run the 50K long connection in a dell ubuntu labtop.
**config the system to support large socket connection
  * set the file size: /etc/security/limits.conf.
  * echo "3000 61000" >/proc/sys/net/ipv4/ip\_local\_port\_range, or sysctl -w net.ipv4.ip\_local\_port\_range ='3000 61000'** build and run command:
  * start server: build/server/server0 -v=0
  * start client: build/server/client0 --num\_threads=10 --num\_connections=50000 -v=0
    * The client will [issue 50000](https://code.google.com/p/server1/issues/detail?id=50000) connections, and do 10 times rpc call.
  * The test scheme is the client call the server rpc service, then the server call the client's registered service on the connected connection.
  * the server code:http://code.google.com/p/server1/source/browse/trunk/server/posix_main.cpp
  * the client code:http://code.google.com/p/server1/source/browse/trunk/server/posix_client.cpp
  * turn on/off the heapcheck of googleperf-tool to detect the memory leaky.