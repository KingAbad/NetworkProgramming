#include "zhelpers.h"
#include <unistd.h>
#include <string.h>
#include <zmq.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Declaring all the functions*/
//void MainGame();
const char* cardVal1();
const char* cardVal2();
const char* cardVal3();
const char* cardVal4();
const char* cardVal5();
const char* cardVal6();
const char* cardVal7();
const char* cardVal8();
const char* cardVal9();
const char* cardVal10();
const char* cardVal11();
const char* cardVal12();
const char* cardVal13();

int main(void)
{
    /*Connection initialization to Benthernet Broker*/
    void *context = zmq_ctx_new ();
    void *pusher = zmq_socket (context, ZMQ_PUSH);
    void *sub = zmq_socket(context, ZMQ_SUB);

    /*All used vars*/
    char buffer[256]  ; //buffer for messages to sent to the client
    char buffer2[256]; //buffer for messages to sent to the client
    char buffer3[256]; //buffer for messages to sent to the client
    char buffer4[256]; //buffer for messages to sent to the client
    char buffer5[256]; //buffer for messages to sent to the client
    char buffer6[256]; //buffer for messages to sent to the client
    char buffer7[256]; //buffer for messages to sent to the client
    char buffer8[256]; //buffer for messages to sent to the client
    char buffer9[256]; //buffer for messages to sent to the client
    char buffer10[256]; //buffer for messages to sent to the client
    char buffer11[256]; //buffer for messages to sent to the client
    char buffer12[256]; //buffer for messages to sent to the client
    char buffer13[256]; //buffer for messages to sent to the client
    char buffer14[256]; //buffer for messages to sent to the client
    char buffer15[256]; //buffer for messages to sent to the client
    char buffer16[256]; //buffer for messages to sent to the client
    char buffer17[256]; //buffer for messages to sent to the client
    char buffer18[256]; //buffer for messages to sent to the client
    char buffer19[256]; //buffer for messages to sent to the client
    char buffer20[256]; //buffer for messages to sent to the client
    char buffer21[256]; //buffer for messages to sent to the client
    char buffer22[256]; //buffer for messages to sent to the client
    char buffer23[256]; //buffer for messages to sent to the client
    char buffer24[256]; //buffer for messages to sent to the client
    char buffer25[256]; //buffer for messages to sent to the client

    //char buffer23[256]; //buffer for messages to sent to the client

    int stringToInt;
    int blackJackAgreement = 0;
    int scoreToBeat = 17;
    int rndCard,gameScore = 0,placeCard;
    char *p;
    char *pMod;

    /*Connecting to the broker*/
    zmq_connect(pusher, "tcp://localhost:24041");
    zmq_connect(sub, "tcp://localhost:24042");

    /*Sub en Push protocol*/
    char pushtask[]     = "Blackjack!<task<Abad>"; //Is the same as the subbed TASK
    char subanswer[]    = "Blackjack?<answer>";    //Is the same as the pushed ANSWER
    char pushanswer[]   = "Blackjack!<answer>";    //Is the same as the subbed ANSWER
    //char subtask[]      = "Blackjack?<task<Abad>"; //Is the same as the pushed TASK
    char pushanswerCard[] = "Blackjack!<answer<card>";

    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subanswer, strlen(subanswer));
    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subanswer, strlen(subanswer));
    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subanswer, strlen(subanswer));
    //zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subanswer, strlen(subanswer));
    //char pushanswer[]   = "Blackjack!>Abad>";
    //char subtask[]      = "Blackjack?>Abad>";

    printf("SERVICE STARTED SUCESSFULLY\n\n");
    srand(time(NULL));


    /*Message to the client*/
    strncpy(buffer, pushtask, 22);
    strncat(buffer, "Do you want to play the game?\n1 = proceed & 0 = exit\n\n", 128);
    s_send(pusher, buffer);


    /*Message received*/
    zmq_recv(sub, buffer2, 256, 0);

    printf("%s\n", buffer2);
    p = strchr(buffer2,'>');
    pMod = p+1;
    stringToInt = atoi(pMod);
    blackJackAgreement = stringToInt;

    if(blackJackAgreement == 1)
    {

        /*Message to the client*/
        //sprintf(buffer,"");
        strncpy(buffer3, pushanswer, 100);
        strncat(buffer3, "GOODLUCK!\n", 128);
        s_send(pusher, buffer3);
        //printf("GOODLUCK!\n");

        /*Message to the client
        strncpy(buffer3, pushanswerCard, 100);
        strncat(buffer3,cardVal1(),80);
        s_send(pusher, buffer3);*/


         while(gameScore <=21)
        {
        rndCard = rand()%13+1;
        if(rndCard == 1)
        {
            /*Message to the client*/
            strncpy(buffer4, pushanswerCard, 100);
            strncat(buffer4,cardVal1(),79);
            s_send(pusher, buffer4);
            gameScore = gameScore + 1;

        }
        else if(rndCard == 2)
        {
            strncpy(buffer5, pushanswerCard, 100);
            strncat(buffer5,cardVal2(),79);
            s_send(pusher, buffer5);
            gameScore = gameScore + 2;
        }
        else if(rndCard == 3)
        {
            strncpy(buffer6, pushanswerCard, 100);
            strncat(buffer6,cardVal3(),79);
            s_send(pusher, buffer6);
            gameScore = gameScore + 3;
        }
         else if(rndCard == 4)
        {
            strncpy(buffer7, pushanswerCard, 100);
            strncat(buffer7,cardVal4(),79);
            s_send(pusher, buffer7);
            gameScore = gameScore + 4;
        }
         else if(rndCard == 5)
        {
            strncpy(buffer8, pushanswerCard, 100);
            strncat(buffer8,cardVal5(),79);
            s_send(pusher, buffer8);
            gameScore = gameScore + 5;
        }
         else if(rndCard == 6)
        {
            strncpy(buffer9, pushanswerCard, 100);
            strncat(buffer9,cardVal6(),79);
            s_send(pusher, buffer9);
            gameScore = gameScore + 6;
        }
         else if(rndCard == 7)
        {
            strncpy(buffer10, pushtask, 100);
            strncat(buffer10,cardVal7(),79);
            s_send(pusher, buffer10);
            gameScore = gameScore + 7;
        }
         else if(rndCard == 8)
        {
            strncpy(buffer11, pushanswerCard, 100);
            strncat(buffer11,cardVal8(),79);
            s_send(pusher, buffer11);
            gameScore = gameScore + 8;
        }
         else if(rndCard == 9)
        {
            strncpy(buffer12, pushanswerCard, 100);
            strncat(buffer12,cardVal9(),79);
            s_send(pusher, buffer12);
            gameScore = gameScore + 9;
        }
         else if(rndCard == 10)
        {
            strncpy(buffer13, pushanswerCard, 100);
            strncat(buffer13,cardVal10(),79);
            s_send(pusher, buffer13);
            gameScore = gameScore + 10;
        }
         else if(rndCard == 11)
        {
            strncpy(buffer14, pushanswerCard, 100);
            strncat(buffer14,cardVal11(),79);
            s_send(pusher, buffer14);
            gameScore = gameScore + 11;
        }
         else if(rndCard == 12)
        {
            strncpy(buffer15, pushanswerCard, 100);
            strncat(buffer15,cardVal12(),79);
            s_send(pusher, buffer15);
            gameScore = gameScore + 12;
        }
         else if(rndCard == 13)
        {
            strncpy(buffer16, pushanswerCard, 100);
            strncat(buffer16,cardVal13(),79);
            s_send(pusher, buffer16);
            gameScore = gameScore + 13;
        }
        if (gameScore>=1 && gameScore <=5 )
        {
            strncpy(buffer17, pushanswer, 100);
            strncat(buffer17, "Dont worry place a card you can't lose\n", 39);
            s_send(pusher, buffer17);

        }
        else if(gameScore>=6 && gameScore <=10 )
        {
            strncpy(buffer18, pushanswer, 100);
            strncat(buffer18, "There is a very small chance you can lose so go for it\n", 55);
            s_send(pusher, buffer18);

        }
         else if(gameScore>=11 && gameScore <=15 )
        {
            strncpy(buffer19, pushanswer, 100);
            //40 chars
            strncat(buffer19, "Now it's getting intense so be carefull!\n", 128);
            s_send(pusher, buffer19);

        }
         else if(gameScore>=16 && gameScore <=20 )
        {
            strncpy(buffer20, pushanswer, 100);
            strncat(buffer20, "Just do it if you're feeling lucky!\n", 46);
            s_send(pusher, buffer20);

        }
       /* strncpy(buffer20, pushanswer, 100); STILL HAVE TO SEND THIS ONE
        strncat(buffer20, "Just do it if you're feeling lucky!\n", 128);
        s_send(pusher, buffer20);*/
        printf("your current score is %d\n",gameScore);
        if (gameScore >21)
        {
            //printf("\nYOU LOST ALL OF YOUR MONEY!!!!\n");


            /*strncpy(buffer23, pushanswer, 100);
            strncat(buffer23, "\nYOU LOST ALL OF YOUR MONEY!!!!\n", 46);
            s_send(pusher, buffer23);*/

            /*strncpy(buffer21, pushanswer, 100);
            strncat(buffer21, "Do you want to try again\n", 128);
            s_send(pusher, buffer20);*/

            /*Message received*/
           // zmq_recv(sub, buffer22, 256, 0);

           /* printf("%s\n", buffer22);
            p = strchr(buffer22,'>');
            pMod = p+1;
            stringToInt = atoi(pMod);
            blackJackAgreement = stringToInt;*/


           // printf("Do you want to place a card?\n\n");
           // gameScore = 0;
            strncpy(buffer25, pushanswer, 100);
            //40 chars
            strncat(buffer25, "\nYOU LOST THE BET\n", 128);
            s_send(pusher, buffer25);

           break;

        }
        strncpy(buffer21, pushanswer,100);
        strncat(buffer21, "Do you want to place a card?",128);
        s_send(pusher, buffer21);



        /*Message received*/
        zmq_recv(sub, buffer22, 256, 0);

        printf("%s\n", buffer22);
        p = strchr(buffer22,'>');
        pMod = p+1;
        stringToInt = atoi(pMod);
        placeCard = stringToInt;

       // printf(".");

        //scanf("%d",&placeCard);
        if (placeCard == 2 && gameScore > scoreToBeat)
        {
            strncpy(buffer23, pushanswer, 100);
            strncat(buffer23, "\nYOU WON THE BET\n", 46);
            s_send(pusher, buffer23);

            break;
        }
        else if(placeCard == 2 && gameScore < scoreToBeat)
       {
           strncpy(buffer24, pushanswer, 100);
           //40 chars
           strncat(buffer24, "\nYOU LOST THE BET\n", 128);
           s_send(pusher, buffer24);
            break;
       }


        }
    }

     return 0;
}

/*
void MainGame()
{
}*/


/*Cards from 1 to 13*/

const char* cardVal1()
{
 static char card1[62]= " \n _______ \n|       |\n|       |\n|   1   |\n|       |\n|_______|\n";
    return card1;
}

const char* cardVal2()
{
 static char card2[62]= " \n _______ \n|       |\n|       |\n|   2   |\n|       |\n|_______|\n";
    return card2;
}

const char* cardVal3()
{
 static char card3[62]= " \n _______ \n|       |\n|       |\n|   3   |\n|       |\n|_______|\n";
    return card3;
}


const char* cardVal4()
{
 static char card4[62]= " \n _______ \n|       |\n|       |\n|   4   |\n|       |\n|_______|\n";
    return card4;
}

const char* cardVal5()
{
 static char card5[62]= " \n _______ \n|       |\n|       |\n|   5   |\n|       |\n|_______|\n";
    return card5;
}

const char* cardVal6()
{
 static char card6[62]= " \n _______ \n|       |\n|       |\n|   6   |\n|       |\n|_______|\n";
    return card6;
}

const char* cardVal7()
{
 static char card7[62]= " \n _______ \n|       |\n|       |\n|   7   |\n|       |\n|_______|\n";
    return card7;
}

const char* cardVal8()
{
 static char card8[62]= "\n _______ \n|       |\n|       |\n|   8   |\n|       |\n|_______|\n";
    return card8;
}
const char* cardVal9()
{
 static char card9[62]= " \n _______ \n|       |\n|       |\n|   9   |\n|       |\n|_______|\n";
    return card9;
}

const char* cardVal10()
{
 static char card10[62]= "\n _______ \n|       |\n|       |\n|   10   |\n|       |\n|_______|\n";
    return card10;
}

const char* cardVal11()
{
 static char card11[62]= " \n _______ \n|       |\n|       |\n|  11   |\n|       |\n|_______|\n";
    return card11;
}

const char* cardVal12()
{
 static char card12[62]= " \n _______ \n|       |\n|       |\n|  12   |\n|       |\n|_______|\n";
    return card12;
}

const char* cardVal13()
{
 static char card13[62]= " \n _______ \n|       |\n|       |\n|  13   |\n|       |\n|_______|\n";
    return card13;
}
