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

    zmq_connect(pusher, "tcp://benternet.pxl-ea-ict.be:24041"); //push
    zmq_connect(sub, "tcp://benternet.pxl-ea-ict.be:24042");    //pull

    char subtask[]      = "Blackjack?<task>"; //Subscribed to the question asked by the service

    char buffer[256]; //buffer where the received message is stored in
    char buffer2[17] = {'\0'};; //buffer where the received message is stored in
    char scanVar[20];

    char pushanswer[]   = "Blackjack!<Abad>";
    //char pushtask[] = "Blackjack?<Abad>";
    //char subanswer[]= "example>answer!>EduardoB!!>";


    char *rqbuf = NULL;
    char *itoabuf = NULL;
    char *rcvbuf = "blablabla";

    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subtask, strlen(buffer));


    /*Prints the first message*/
    zmq_recv(sub, buffer, 256, 0);
    printf("%s", buffer);

    /*Reply to the service*/
    scanf("%c", &scanVar);
    strncpy(scanVar, pushanswer , 128);
    s_send(pusher, scanVar);

    //zmq_send(pusher,)

    //strncpy(buffer, pubTopic, 22);

   // scanf("%c", scanVar);
    //strncat(buffer, scanVar , 128);
    //s_send(pusher, buffer);*/


    return 0;

}
