set(SOURCES
Connection.cpp
HttpServer.cpp
HttpHeader.cpp
curl/Client.cpp
JSHttpClient.cpp
JSHttpServer.cpp
JSWebSocketClient.cpp
NetAsync.cpp
curl/SocketAdapter.cpp
curl/MultiAdapter.cpp
websocket/Message.cpp
websocket/Client.cpp
websocket/Manager.cpp
MimeTypes.cpp
Reply.cpp
RequestParser.cpp
)

set(HEADERS
# no public headers
)

find_package(OpenSSL)
list( APPEND EXTERNALS OPENSSL )


if(NOT WIN32)
    find_package(Boost COMPONENTS thread system regex)
endif(NOT WIN32)

if(WIN32)
    list( APPEND EXTERNALS PTHREADVC )
endif(WIN32)

y60_add_component(
    NetAsync
    SOURCES ${SOURCES}
    HEADERS ${HEADERS}
    DEPENDS asldom aslnet spidermonkey y60jsbase y60jslib
    EXTERNS ${EXTERNALS} 
)

y60_add_jstest(HttpServer mod_Async)
y60_add_jstest(HttpClient mod_Async)
y60_add_jstest(WebSocketClient mod_Async)

