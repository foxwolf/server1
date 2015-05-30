# Introduction #

Add your content here.
This is a cross-platform full dual rpc protobuf service, there are some point:
  * cross-platform, it is because the boost asio and protobuf are cross-platform.
  * It implement the protobuf rpc service.
  * dual rpc, the client can call server rpc service, and the server can call back the client service, the example like:
    * 1. server\_connection.RegisterService(server\_service);
    * 2. server start.
    * 3. client\_connection.RegisterService(client\_serivce)
    * 4. client\_connection connect to server
    * 5. client stub call to server service.
    * 6. // In the server
    * 7. The server get the client connection and call the client service.
    * 8. The server call back to client is useful when server need to push emergence message to client, it is a good elaborate to the "long connection".
  * a lightweight thread pool.

# Details #
  * The server example: http://code.google.com/p/server1/source/browse/trunk/server/posix_main.cpp
  * The client example: http://code.google.com/p/server1/source/browse/trunk/server/posix_client.cpp