#ifndef PROJ1_H 
#define PROJ1_H

/* TODO: Server and Client classes */

class Server {
	public:
		Server();
		int sock();
		void gen_price(int sock);
		void process_buy_request(int sock);
	private:
		struct sockaddr_in serv_addr;
		char buffer[256];
		time_t time_img;
		double price;
};

class Client {
	public:
		Client(char *hostname, int portno);
		void get_price();
		void gen_buy_request();
	private:
		int sockfd;
		struct sockaddr_in serv_addr;
		struct hostent *server;
		char buffer[256];
};

#endif
