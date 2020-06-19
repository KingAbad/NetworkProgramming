#include "zhelpers.h"
#include <unistd.h>
#include <string.h>
#include <zmq.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Declaring all the functions*/
//void MainGame();
void cardVal1();
void cardVal2();
void cardVal3();
void cardVal4();
void cardVal5();
void cardVal6();
void cardVal7();
void cardVal8();
void cardVal9();
void cardVal10();
void cardVal11();
void cardVal12();
void cardVal13();

int main(void)
{
    /*Connection initialization to Benthernet Broker*/
    void *context = zmq_ctx_new ();
    void *pusher = zmq_socket (context, ZMQ_PUSH);
    void *sub = zmq_socket(context, ZMQ_SUB);

    zmq_connect(pusher, "tcp://benternet.pxl-ea-ict.be:24041");
    zmq_connect(sub, "tcp://benternet.pxl-ea-ict.be:24042");

    char buffer[256]; //buffer for messages to sent to the client
    char buffer2[256]; //buffer for messages to sent to the client
    char *p;
    char *pMod; //after the < charachter
    int convertedToString;

    char pushtask[]     = "Blackjack?<task<Abad>"; //The question to be asked the client
    char subanswer[]    = "Blackjack!<answer<Abad>";

    //char pushanswer[]   = "Blackjack!>Abad>";
    //char subtask[]      = "Blackjack?>Abad>";

  //  zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subanswer, strlen(buffer));

    //s_send(pusher, pushtask);
    int blackJackAgreement = 0;
    int rndCard,gameScore = 0,placeCard;
    int sendMessage =1;
    printf("SERVICE STARTED SUCESSFULLY\n\n");
    srand(time(NULL));

    strncpy(buffer, pushtask, 22);
    strncat(buffer, "Do you want to play the game?\n1 = proceed & 0 = exit\n\n", 128);
    s_send(pusher, buffer);

    //parsedVal = strchr()
    //scanf("%d",&blackJackAgreement);
    /*if(blackJackAgreement > 1 )
    {
        printf("Please choose 1 or 0\n1 is to play & 0 is to exit\n\n");
        printf("\n1 = proceed & 0 = exit\n");

    scanf("%d",&blackJackAgreement);
    }*/

    zmq_setsockopt(sub, ZMQ_SUBSCRIBE, subanswer, strlen(buffer2));
    zmq_recv(sub, buffer2, 256, 0);
    p = strchr(buffer2,'>');
    pMod = p+1;
    printf("%s \n",buffer2);
    convertedToString = atoi(pMod);
    //printf("%c \n",pMod);
    blackJackAgreement = convertedToString;

    if(blackJackAgreement == 1)
    {
        printf("GOODLUCK!\n");
         while(gameScore <=21)
        {
        rndCard = rand()%13+1;
        if(rndCard == 1)
        {
            cardVal1();
            gameScore = gameScore + 1;

        }
        else if(rndCard == 2)
        {
            cardVal2();
            gameScore = gameScore + 2;
        }
        else if(rndCard == 3)
        {
            cardVal3();
            gameScore = gameScore + 3;
        }
         else if(rndCard == 4)
        {
            cardVal4();
            gameScore = gameScore + 4;
        }
         else if(rndCard == 5)
        {
            cardVal5();
            gameScore = gameScore + 5;
        }
         else if(rndCard == 6)
        {
            cardVal6();
            gameScore = gameScore + 6;
        }
         else if(rndCard == 7)
        {
            cardVal7();
            gameScore = gameScore + 7;
        }
         else if(rndCard == 8)
        {
            cardVal8();
            gameScore = gameScore + 8;
        }
         else if(rndCard == 9)
        {
            cardVal9();
            gameScore = gameScore + 9;
        }
         else if(rndCard == 10)
        {
            cardVal10();
            gameScore = gameScore + 10;
        }
         else if(rndCard == 11)
        {
            cardVal11();
            gameScore = gameScore + 11;
        }
         else if(rndCard == 12)
        {
            cardVal12();
            gameScore = gameScore + 12;
        }
         else if(rndCard == 13)
        {
            cardVal13();
            gameScore = gameScore + 13;
        }
        if (gameScore>=1 && gameScore <=5 )
        {
            printf("Dont worry place a card you can't lose\n");
        }
        else if(gameScore>=6 && gameScore <=10 )
        {
            printf("There is a very small chance you can lose so go for it\n");
        }
         else if(gameScore>=11 && gameScore <=15 )
        {
            printf("Now it's getting intense so be carefull!\n");
        }
         else if(gameScore>=16 && gameScore <=20 )
        {
            printf("Just do it if you're feeling lucky!\n");
        }
        printf("your current score is %d\n",gameScore);
        if (gameScore >21)
        {
            printf("\nYOU LOST ALL OF YOUR MONEY!!!!\n");
            printf("Do you want to try again\n");
            scanf("%d",&blackJackAgreement);
           // printf("Do you want to place a card?\n\n");
            gameScore = 0;
            //break;
        }
        printf("Do you want to place a card? ");
        scanf("%d",&placeCard);
        if (placeCard == 0 || placeCard >1)
        {
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

void cardVal1()
{
    printf(" _______ \n"
           "|       |\n"
           "|  ACE  |\n"
           "|   1   |\n"
           "|       |\n"
           "|_______|\n");

}

void cardVal2()
{
    printf(" _______ \n"
           "|       |\n"
           "|       |\n"
           "|   2   |\n"
           "|       |\n"
           "|_______|\n");

}

void cardVal3()
{
    printf(" _______ \n"
           "|       |\n"
           "|       |\n"
           "|   3   |\n"
           "|       |\n"
           "|_______|\n");
}



void cardVal4()
{
    printf(" _______ \n"
           "|       |\n"
           "|       |\n"
           "|   4   |\n"
           "|       |\n"
           "|_______|\n");
}

void cardVal5()
{
    printf(" _______ \n"
           "|       |\n"
           "|       |\n"
           "|   5   |\n"
           "|       |\n"
           "|_______|\n");
}

void cardVal6()
{
    printf(" _______ \n"
           "|       |\n"
           "|       |\n"
           "|   6   |\n"
           "|       |\n"
           "|_______|\n");
}

void cardVal7()
{
    printf(" _______ \n"
           "|       |\n"
           "|       |\n"
           "|   7   |\n"
           "|       |\n"
           "|_______|\n");
}

void cardVal8()
{
    printf(" _______ \n"
           "|       |\n"
           "|       |\n"
           "|   8   |\n"
           "|       |\n"
           "|_______|\n");
}

void cardVal9()
{
    printf(" _______ \n"
           "|       |\n"
           "|       |\n"
           "|   9   |\n"
           "|       |\n"
           "|_______|\n");
}

void cardVal10()
{
    printf(" _______ \n"
           "|       |\n"
           "|       |\n"
           "|  10   |\n"
           "|       |\n"
           "|_______|\n");
}

void cardVal11()
{
    printf(" _______ \n"
           "|       |\n"
           "| JACK  |\n"
           "|  11   |\n"
           "|       |\n"
           "|_______|\n");
}

void cardVal12()
{
    printf(" _______ \n"
           "|       |\n"
           "| QUEEN |\n"
           "|  12   |\n"
           "|       |\n"
           "|_______|\n");
}

void cardVal13()
{
    printf(" _______ \n"
           "|       |\n"
           "| KING  |\n"
           "|  13   |\n"
           "|       |\n"
           "|_______|\n");
}

