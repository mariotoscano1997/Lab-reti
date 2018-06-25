#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

int main( int argc , char** argv){
	int pid=fork();
	if(pid==0){
		int sockfd, n;
		extern int errno;
		struct sockaddr_in locale, sender;
		socklen_t len= sizeof(sender);
		char msg[81];

		if(argc<2) { printf("inserire porta\n"); return 0;}
		if((sockfd=socket(AF_INET, SOCK_DGRAM,0))<0){
			printf("errore nel socket\n");
			return 2;
		}
		memset(&locale,0,sizeof(locale));
		locale.sin_family= AF_INET;
		locale.sin_addr.s_addr=htonl(INADDR_ANY);
		locale.sin_port=htons(atoi(argv[1]));
		if(bind(sockfd,(struct sockaddr*)&locale, sizeof(locale))<0){
			printf("errore nel bind\n");
			return 3;
		}
		while(1){
			printf("server in attesa\n");
			recvfrom(sockfd, msg, 81, 0, (struct sockaddr *)&sender, &len);
		}
	}
}
else {

}
