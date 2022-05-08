#include "zmq/zmq.hpp"
#include <string>
#include <iostream>

int main(){
    using namespace std;

    zmq::context_t ctx(1);
    zmq::socket_t sock_server(ctx, ZMQ_REP);
    sock_server.bind("tcp://*:5555");

    while (true){
        zmq::message_t msg_req;

        sock_server.recv(&msg_req);
        cout << "Received Hello " << endl;

        zmq_sleep(1);

        zmq::message_t msg_re;
        memcpy_s(msg_req.data(), sizeof(msg_req.data()), "World", 5);
        sock_server.send(msg_re);
    }

    return 0;
}