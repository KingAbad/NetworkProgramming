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
    //char buffer[256] = {'\0'}; //buffer where the received message is stored in
    char buffer[256]; //buffer where the received message is stored in
    char buffer2[256] = {'\0'}; //buffer where the received message is stored in
    char buffer3[256]; //buffer for messages to sent to the client
    char buffer4[256];
    char buffer5[256]; //buffer where the received message is stored in
    char buffer6[256]; //buffer where the received message is stored in
    char buffer7[256]; //buffer where the received message is stored in
    char buffer8[256]; //buffer where the received message is stored in
    char buffer9[256]; //buffer where the received message is stored in
    char buffer10[256]; //buffer where the received message is stored in
    char buffer11[256]; //buffer where the received message is stored in
    char scanVar[1];

    zmq_connect(pusher, "tcp://localhost:24041"); //push
    zmq_connect(sub, "tcp://localhost:24042");    //pull
    /*Sub en Push protocol*/
    char pushtask[]     = "Blackjack!<task<Abad>"; //Is the same as the subbed TASK
    char subanswer[]    = "Blackjack!<answer>";    //Is the same as the pushed ANSWER
    char subanswerCard[] = "Blackjack!<answer<card>";
    char pushanswer[]   = "Blackjack?<answer>";    //Is the same as the subbed ANSWER
    char subtask[]      = "Blackjack!<task<Abad>"; //Is the same as the pushed TASK

    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subtask, strlen(subtask));
    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subanswer, strlen(subanswer));
    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subanswerCard, strlen(subanswerCard));
    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subanswer, strlen(subanswer));
    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subanswer, strlen(subanswer));


    /*Prints the message received from the service*/
    zmq_recv(sub, buffer, 256, 0);
    printf("%s", buffer);


    /*Reply to the service PUSH*/
    scanf("%c", &*scanVar);
    strncpy(buffer2, pushanswer , 22);
    strncat(buffer2, scanVar,1);
    s_send(pusher, buffer2);


    /*Prints the message received from the service GL*/

    //sprintf(buffer,"");
    zmq_recv(sub, buffer3, 256, 0);
    printf("%s", buffer3);
    //sprintf(buffer,"%s",s_recv(sub));


    /*Prints the message received from the service CARD*/

    //sprintf(buffer,"");
    zmq_recv(sub, buffer4, 256, 0);
    printf("%s", buffer4);
    //sprintf(buffer,"%s",s_recv(sub));


    /*Prints the message received from the service DW*/

    //sprintf(buffer,"");
    zmq_recv(sub, buffer5, 256,0);
    printf("%s", buffer5);
    //sprintf(buffer,"%s",s_recv(sub));


    /*Prints the message received from the service PLACE CARD*/

    //sprintf(buffer,"");
    zmq_recv(sub, buffer9, 256, 0);
    printf("%s", buffer9);
    //sprintf(buffer,"%s",s_recv(sub));


    /*Reply to the service PUSH*/
    scanf("%c", &*scanVar);
    strncpy(buffer10, pushanswer ,150);
    strncat(buffer10, scanVar,1);
    s_send(pusher, buffer10);

    /*Prints the message received from the service PLACE CARD*/

    //sprintf(buffer,"");
    zmq_recv(sub, buffer11, 256, 0);
    printf("%s", buffer11);
    //sprintf(buffer,"%s",s_recv(sub));

    return 0;
}
