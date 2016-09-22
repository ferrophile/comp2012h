***readme.txt***

COMP2012H Project 1
Name:			Hong Wing PANG
Stu ID:			20315504
Last updated:	21-09-2016

To illustrate the current situation, I first lists out the various connections needed for completing this project.

Server
1. Write price and time to client
2. Read buy request from client
3. Write response to client upon receiving request in (2)

Client
1. Read price and time from server
2. Submit buy request to server
3. Read response from server to decide if buy is successful

There is only one case where the client writes to server, so there is no disambiguation. However, server writes to client for various different purposes. To differentiate between different types of messages, some sort of protocol is required.

While one can create send and receive functions for both server and client, this would look unwieldy in my opinion (unless if server and client share the same parent class). Without changing the given class structure, I only gave server class a send function, and similarly a receive function for client class. Both functions deal with messages in three parts - id to differentiate type of message; length of message; and content of message.

Another issue encountered is that price generation is done within the get_price function, which is called by each one of the processes (depends on no. of clients connected). Since process can generate a price to overwrite previous records, at the instant of changing price different clients can get different prices values. My solution to this is to add a 0.1 sec delay after price generation and before updating the clients, using the usleep() function. This is to ensure, after the brief delay, all processes have updated the price and the value in *price is safe to send to the clients.