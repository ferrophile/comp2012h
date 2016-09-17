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
	price = (char *)mmap(NULL, sizeof *price, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	price_buy = (char *)mmap(NULL, sizeof *price_buy, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	time_buy = (char *)mmap(NULL, sizeof *time_buy, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	bzero(price, 10);
	bzero(price_buy, 10);
	bzero(time_buy, 30);
}

void Client::get_price() {
	char id = read_message(buffer, sockfd);
	time_t time_img = time(NULL);
	switch (id) {
		case MSG_PRICE:
			printf("%s ", buffer);
			strcpy(price, buffer);
			break;
		case MSG_TIME:
			printf("%s", buffer);
			break;
		case MSG_REPLY:
			//printf("Cli: %s, Ser: %s\n", price_buy, buffer);
			printf("client buy  at %s at %s", price_buy, time_buy);
			printf("server sell at %s at %s", price, ctime(&time_img));
			printf("all times approx\n");
			printf("buy %s from server!\n", (strcmp(price, price_buy) ? "FAILED" : "SUCCESSFUL"));
			break;
	}
}

void Client::gen_buy_request() {
	int n;
	char c = getchar();
	if ((int)c == 10) {
		time_t time_img = time(NULL);
		printf("from client: client buy at %s at %s", price, ctime(&time_img));
		strcpy(price_buy, price);
		strcpy(time_buy, ctime(&time_img));
		n = write(sockfd, price, strlen(price));
		if (n < 0) {
			perror("ERROR writing to socket");
			exit(0);
		}
	}
}

MSG_ID Client::read_message(char *body, int sockfd) {
	int n;
	char id, len;
	n = read(sockfd, &id, 1);
	n = read(sockfd, &len, 1);
	bzero(buffer, 256);
	n = read(sockfd, body, (int)len);
	if (n < 0) {
		perror("ERROR reading from socket");
		exit(1);
	}
	return (MSG_ID)id;
}
