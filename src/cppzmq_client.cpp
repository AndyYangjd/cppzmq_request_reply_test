#include "zmq/zmq.hpp"
#include <string>
#include <iostream>

int main(){
    using namespace std;

    zmq::context_t ctx(1);

    cout<<"Connecting to hello world server..."<< endl;

    zmq::socket_t sock_requester(ctx, zmq::socket_type::req);
    sock_requester.connect("tcp://localhost:5555");

    for (int request_nbr = 0; request_nbr < 10; ++request_nbr) {
        zmq_msg_t msg_req;
        zmq_msg_init_size(&msg_req, 5);
        memcpy_s(zmq_msg_data(&msg_req), sizeof(msg_req),"Hello", 5);
        cout << "Sending Hello " << request_nbr << endl;

        zmq_msg_send(&msg_req, sock_requester, 0);
        zmq_msg_close(&msg_req);

        zmq_msg_t msg_re;
        zmq_msg_init(&msg_re);
        zmq_msg_recv(&msg_re, sock_requester, 0);
        cout << "Received World " << request_nbr << endl;
        zmq_msg_close(&msg_req);
    }
    zmq_sleep(2);
    zmq_close(&sock_requester);
    zmq_ctx_destroy(&ctx);

    return 0;
}
