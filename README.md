# Project - BlackJack Using ZMQ

The main goal of this project was to program a service that can bring a certain logic over ZMQ to a client. My project was a simple BlackJack game to illustrate the working of this principle. I learned a lot from this project and I am more confident in my network programming skills as of now.


## Source Roadmap

```
Client_BlackJack               directory containing Client code of the BlackJack project
Service_BlackJack              directory containing Service code of the BlackJack project
MinZMQt_Benternet.exe          Executable for Benternet broker
MinZMQt_localhost.exe          Executable for MinZMQT localhost
ZMQbroker_localhost.exe        Executable for ZMQbroker localhost
```

## How to set things up
<details> 
  
## Opening the broker

<details>
 
**Step by step guide**
* For a localhost connection make sure your ZMQ connection is as step 2 and 3
* zmq_connect(pusher, "tcp://localhost:24041"); //push
* zmq_connect(sub, "tcp://localhost:24042");    //pull
* When this is alright you can open up the three executables
* Check if you are receiving the pings on the MinZMQt_localhost.exe send from MinZMQt_Benternet.exe
* Once this is done you can start opening the client and service code.

**Note:**
You have to have all three executables up and running in order for it to work.
</details>  

## How to compile the game

<details>
 
**Step by step guide**
* Open the QT programming environment
* Open both the Client_BlackJack.pro and the Service_BlackJack.pro files inside QT.
* Now build and comile the client code first and afterwards the service code.
* The game should have been started now and you can play.
* If the score goes beyond 21 the game stops.
* If the player decides to stop before a score of 17 the player loses.
* If the player has a score higher then 17 and lower then 21 and stops the bet he wins.

**Note:**
Make sure you have the include en lib in the same directory as your project folder.
</details> 

## Built With

* [QT Creator](https://www.qt.io/download)       - Programming environment used for programming the game
* [Notepad++](https://notepad-plus-plus.org/downloads/) -  Programming environment used for quick debugging


## Project participants

* **Bart Stukken**      - Professor - [LinkedIn](https://www.linkedin.com/in/bart-stukken/)
* **Abad Sethi**        - Developer  - [LinkedIn](https://www.linkedin.com/in/abad-sethi-83246a170/)

<p align="left"><img src="./readme_Images/pxl_logo.png"></p>
