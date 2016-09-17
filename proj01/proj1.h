#ifndef PROJ1_H 
#define PROJ1_H

//static double *price;

class Server {
	public:
		Server();
		int sock();
		void gen_price(int sock);
		void process_buy_request(int sock);
	private:
		double rand_price();
		struct sockaddr_in serv_addr;
		char buffer[256];
		time_t time_img;
		double *price;
		int *update_flag;
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
		char *price;
};

#endif
