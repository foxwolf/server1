a c++ network server/client framework , there are some point:
  * cross-platform, it is constructed on the boost asio and protobuffer, both the boost asio and protobuf are cross-platform.
  * It implement the protobuf rpc service.
  * dual rpc, the client can call server rpc service, the server can call back the client service, the server call back to client is useful when server need to push emergence message to client, it is a good elaborate to the "long connection".
  * With a cross-platform producer consumer queue and a cross-platform thread pool base on boost thread.
  * Integrate with a cross-platform timer.
  * Integrate with the logging system: glog
  * Integrate with the testing framework: gtest
  * Integrate with the commandline processing: gflag
  * Integrate with openssl/zlib
  * Unify all the above under the scons.

**Benchmark, on the debug version, server/client on the same machine:
  * Machine: 2 core, CPU 2.8GHZ, 2G memory dell workstation, ubuntu.
  * $build/server/server0 -v=-1
  * $time build/server/client0 -v=0 --num\_threads=20 --num\_connections=4000
    * real    0m15.373s
    * user    0m13.562s
    * sys     0m3.979s
    * The client will send num\_threads multiple num\_connections  request to server and wait the response, and to each request of the client, the server will first send the response then init another request to client and wait response.
So there is num\_threads multiple num\_connections multiple 2 request/reply.
The QPS is:20 multiple 4000 multiple 2 divide 15.373 = 10407 request/response per second.**

