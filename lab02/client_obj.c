#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

class Client {
    public:
        Client(hostent* server, int portno);
        int get_sock();
        void close_sock();
    private:
        struct sockaddr_in cli_serv_addr;
        struct hostent *cli_server;
        int cli_portno;
        int cli_sockfd;
};

Client::Client(hostent* server, int portno) {
    cli_server = server;
    cli_sockfd = 0;

    if (cli_server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &cli_serv_addr, sizeof(cli_serv_addr));
    cli_serv_addr.sin_family = AF_INET;
    bcopy((char *)cli_server->h_addr, 
         (char *)&cli_serv_addr.sin_addr.s_addr,
         cli_server->h_length);
    cli_serv_addr.sin_port = htons(portno);
}

int Client::get_sock() {
    cli_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (cli_sockfd < 0)
        error("ERROR opening socket");
    if (connect(cli_sockfd,(struct sockaddr *) &cli_serv_addr,sizeof(cli_serv_addr)) < 0)
        error("ERROR connecting");
    return cli_sockfd;
}

void Client::close_sock() {
    close(cli_sockfd);
}

int main(int argc, char *argv[])
{
    int n, sockfd, portno;
    struct hostent *server;
    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    server = gethostbyname(argv[1]);
    portno = atoi(argv[2]);

    Client client(server,portno);
    sockfd = client.get_sock();
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);
    client.close_sock();
    return 0;
}
