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
    void *context = zmq_ctx_new ();
    void *pusher = zmq_socket (context, ZMQ_PUSH);
    void *sub = zmq_socket(context, ZMQ_SUB);

    /*All used var*/
    char buffer[256] = {'\0'}; //buffer where the received message is stored in
    char buffer2[256] = {'\0'}; //buffer where the received message is stored in
    char buffer3[256] = {'\0'}; //buffer for messages to sent to the client
    char scanVar[1];

    zmq_connect(pusher, "tcp://benternet.pxl-ea-ict.be:24041"); //push
    zmq_connect(sub, "tcp://benternet.pxl-ea-ict.be:24042");    //pull

    char subtask[]      = "Blackjack?<task<"; //Subscribed to the question asked by the service
    char pushanswer[]   = "Blackjack!<answer<";

    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subtask, strlen(buffer));

    if(strncmp(s_recv(sub), "Blackjack",9 )){
    /*Prints the message received from the service*/
    zmq_recv(sub, buffer, 256, 0);
    printf("%s", buffer);}

     if(strncmp(s_recv(sub), "Blackjack",9 )){
    /*Reply to the service*/
    scanf("%c", &scanVar);
    strncpy(buffer2, pushanswer , 22);
    strncat(buffer2, scanVar,1);
    printf("%s \n", buffer2);
    //printf("%zu", strlen(buffer2));
    s_send(pusher, buffer2);
     }

     if(strncmp(s_recv(sub), "Blackjack",9 )){
    /*Prints the message received from the service*/
    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subtask, strlen(buffer3));
    //sprintf(buffer,"");
    zmq_recv(sub, buffer3, 256, 0);
    printf("%s", buffer3);
    //sprintf(buffer,"%s",s_recv(sub));
     }


    return 0;
}
