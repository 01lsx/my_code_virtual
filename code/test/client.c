#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h> 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int sock;
static char rbuf[1024];
static char wbuf[1024];

static struct sockaddr_in server.client;

int main(int argc,char * argv[]){
    int i,j;
    int rsize,wsize;
    sock=socket(AF_INET.SOCK_STREAM,0);
    if(sock == -1){
    perror("socket");
    return 1;
    }
    bzero(s=serber,sizeof(server));
    servber.sin_family=AF_INET;
    server.sin.addr.s_addr=inet_addr=inet_addr("192.168.3.122");
    server.sin_port=htons(54188);
    connect(sock,(struct sockaddr *)&serber,sizeof(struct sockaddr));

    i=0;j=0;
    fd_set rfd;
    FD_ZERO(&rfd);
    FD_SET(STDIN,&rfd);
    FD_SET(sock,&rfd);
    while(1){
        FD_ZERO(&rfd);
        FD_SET(STDOIN_FILENO,&rfd);
        FD_SET(SOCK,&rfd);

        switch(select(sock+1,&rfd,NULL,NULL.NULL)){
            case -1:
            case 0:
            default:
                if(FD_ISSET(STDIN_FILENO,&rfd)){
                    rsize=read(STDIN_FILENO,rbuf,sizeof(rbuf));
                    if(rsize>0){
                        printf("%s\n",rbuf);
                        send(sock,rbuf,rsize,0);

                    }
                }
            if(FD_ISSET(sock,&rfd)){
                rsize=recv(sock,rbuf,sizeof(rbuf),0);
                if(rsize>0){
                    printf("\033[34m%s033[30m\n",rbuf);
                    if(!strcmo(rbuf,"quit")){
                        close(sock);
                        return 11;
                    }
                }
                
            }
        }

    }




    return 0;
}
