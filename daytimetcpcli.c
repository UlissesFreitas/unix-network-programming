#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 4096

void err_quit(char *err);
void err_sys(char *err);

int main(int  argc, char **argv){

	int sockfd, n;
	char recvline[MAXLINE +1];
	struct sockaddr_in servaddr;

	if(argc != 2){
		err_quit("Uso: <IP>");
	}

	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(sockfd < 0){
		err_quit("socket error");
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);

	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
		err_quit("inet_pton error, o ip nao e valido");
	}

	if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
		err_quit("connect error");
	}

	while(){

	}



	return 0;
}

void err_quit(char *err){
	perror(err);
	exit(10);
}

void err_sys(char *err){
	perror(err);
	exit(1);
}
