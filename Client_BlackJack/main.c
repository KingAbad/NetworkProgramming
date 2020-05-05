#include "zhelpers.h"
#include <unistd.h>
#include <string.h>
#include <zmq.h>

int main()
{
    void *context = zmq_ctx_new ();
    void *pusher = zmq_socket (context, ZMQ_PUSH);
    void *sub = zmq_socket(context, ZMQ_SUB);

    zmq_connect(pusher, "tcp://benternet.pxl-ea-ict.be:24041");
    zmq_connect(sub, "tcp://benternet.pxl-ea-ict.be:24042");

    char pushName[] = "game>blackjack>AbadS>";


}
