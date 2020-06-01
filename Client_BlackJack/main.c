#include "zhelpers.h"
#include <unistd.h>
#include <string.h>
#include <zmq.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    /*Connection initialization to Benthernet Broker*/
    /*void *context = zmq_ctx_new ();
    void *pusher = zmq_socket (context, ZMQ_PUSH);
    void *sub = zmq_socket(context, ZMQ_SUB);

    zmq_connect(pusher, "tcp://benternet.pxl-ea-ict.be:24041");
    zmq_connect(sub, "tcp://benternet.pxl-ea-ict.be:24042");

    char subTopic[] = "game>blackjack>Task>";
    char pubTopic[] = "game>blackjack>Answer>";
    char buffer[256];
    char scanVar[10];

    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subTopic, strlen(buffer));

    while(1)
    {
    zmq_recv(sub, buffer, 256, 0);
    printf("%s", buffer);

    //zmq_send(pusher,)

    strncpy(buffer, pubTopic, 22);

    scanf("%c", scanVar);
    strncat(buffer, scanVar , 128);
    s_send(pusher, buffer);
    }
    return 0;*/

    for(int i = 0; i <= 9; i++)
    {

        for(int j =0; j <= i; j++)
        {
            printf("*");
        }
         printf("\n");
        if(i == 9)
        {
            printf("\n");
        }
}
}
