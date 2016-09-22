//server.cpp
//Member-function definitions for class Server.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <time.h>
#include "proj1.h"

//Server constructor
//Initializes server address and shared variables
Server::Server() {
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(5001);
	srand (time(NULL));
	time_img = time(NULL);
	
	price = (double *)mmap(NULL, sizeof *price, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	count = (int *)mmap(NULL, sizeof *count, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	
	*price = rand_price();
	*count = 0;
}

//Creates socket and binds it to server address;
//Returns sockfd
int Server::sock() {
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("ERROR opening socket");
		exit(1);
	}
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		perror("ERROR on binding");
		exit(1);
	}
	return sockfd;
}

//Generates a random price every 10 seconds
//Updates information to corresponding client
void Server::gen_price(int sock) {
	//Only runs once per second
	if (time_img == time(NULL))
		return;
	time_img = time(NULL);
	
	if (!(time_img % 10))
		*price = rand_price();
	usleep(100000); //Sleep 0.1s to wait for all process finish
	
	//Sends price
	bzero(buffer, 256);
	sprintf(buffer, "$%.1f", *price);
	send_message(MSG_PRICE, buffer, sock);
	
	//Sends time
	bzero(buffer, 256);
	sprintf(buffer, "%s", ctime(&time_img));
	send_message(MSG_TIME, buffer, sock);
	
	//Print out price and time
	printf("$%.1f %s", *price, ctime(&time_img));
}

//Processes buying request from client
void Server::process_buy_request(int sock) {
	int n;
	bzero(buffer, 256);
	n = read(sock, buffer, 5);
	
	if (n < 0) {
		perror("ERROR reading from socket");
		exit(1);
	}
	if (strlen(buffer)) {
		sleep(1); //simulate processing time
		
		++*count; //increment count
		printf("no of attempts: %d\n", *count);
		
		//sends back current price to client
		bzero(buffer, 256);
		sprintf(buffer, "$%.1f", *price);
		send_message(MSG_REPLY, buffer, sock);
	}
}

//Utility functions

//Returns random price from $0.0 to $9.9
double Server::rand_price() {
	return rand() % 100 / 10.0;
}

//Sends message to client
//id: type of message for client to process
//body: content of message
//sock: socket to send to
void Server::send_message(MSG_ID id, char* body, int sock){
	int n;
	char len = (char)strlen(buffer);
	n = write(sock, (char *)&id, 1);
	n *= write(sock, &len, 1);
	n *= write(sock, buffer, strlen(buffer));
	if (n < 0) {
		perror("ERROR writing to socket");
		exit(0);
	}
}
