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

//Constructor
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

//Creates socket and binds it to server address
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

void Server::gen_price(int sock) {
	if (time_img == time(NULL))
		return;
	time_img = time(NULL);
	
	if (!(time_img % 10))
		*price = rand_price();
	usleep(100000); //Sleep 0.1s to wait for all process finish
	
	bzero(buffer, 256);
	sprintf(buffer, "$%.1f", *price);
	send_message(MSG_PRICE, buffer, sock);
	
	bzero(buffer, 256);
	sprintf(buffer, "%s", ctime(&time_img));
	send_message(MSG_TIME, buffer, sock);	
	printf("$%.1f %s", *price, ctime(&time_img));
}

void Server::process_buy_request(int sock) {
	int n;
	bzero(buffer, 256);
	n = read(sock, buffer, 5); //need to dynamically read length as well
	if (n < 0) {
		perror("ERROR reading from socket");
		exit(1);
	}
	if (strlen(buffer)) {
		sleep(1); //simulate processing time
		
		++*count;
		printf("no of attempts: %d\n", *count);
		
		bzero(buffer, 256);
		sprintf(buffer, "$%.1f", *price);
		send_message(MSG_REPLY, buffer, sock);
	}
	//else lost connection with client
}

//Generates rand double from 0.0 to 9.9
double Server::rand_price() {
	return rand() % 100 / 10.0;
}

void Server::send_message(MSG_ID id, char* body, int sock){
	int n;
	char len = (char)strlen(buffer);
	n = write(sock, (char *)&id, 1);
	n = write(sock, &len, 1);
	n = write(sock, buffer, strlen(buffer));
	if (n < 0) {
		perror("ERROR writing to socket");
		exit(0);
	}
}
