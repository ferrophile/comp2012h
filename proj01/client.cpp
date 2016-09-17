#include <stdio.h>
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
Client::Client(char *hostname, int portno) {
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("ERROR opening socket");
		exit(1);
	}
	server = gethostbyname(hostname);
	if (server == NULL) {
		fprintf(stderr, "ERROR, no such host\n");
		exit(0);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		perror("ERROR connecting");
		exit(1);
	}
	
	bzero(buffer, 256);
	price = static_cast<char*>(mmap(NULL, sizeof *price, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0));
	bzero(price, 10);
}

void Client::get_price() {
	char id = read_message(buffer, sockfd);
	if (id == 1) {
		printf("%s", buffer);
		strcpy(price, buffer);
	}
	if (id == 2)
		printf("%s", buffer);
}

void Client::gen_buy_request() {
	int n;
	char c = getchar();
	if ((int)c == 10) {
		time_t time_img = time(NULL);
		printf("from client: client buy at %sat %s", price, ctime(&time_img));
		n = write(sockfd, price, strlen(price));
		if (n < 0) {
			perror("ERROR writing to socket");
			exit(0);
		}
		
		/*
		bzero(buffer, 256);
		n = read(sockfd, buffer, 255);
		if (n < 0) {
			perror("ERROR reading from socket");
			exit(1);
		}
		printf("%d, %d", strlen(price), strlen(buffer));
		*/
	}
}

char Client::read_message(char *body, int sockfd) {
	int n;
	char id;
	n = read(sockfd, &id, 1);
	bzero(buffer, 256);
	n = read(sockfd, body, 255);
	if (n < 0) {
		perror("ERROR reading from socket");
		exit(1);
	}
	return id;
}
