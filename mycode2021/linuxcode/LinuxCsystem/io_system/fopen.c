#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
    FILE *fd,*fd_out;
    int n;

    fd = fopen("test.c","r");
    if(fd == NULL){
        perror("fopen argv[1]");
        exit(1);
    }
    fd_out = fopen("test2.c","w");
    if(fd_out == NULL){
        perror("fopen argv[2]");
        exit(1);
    }

    while((n = fgetc(fd)) != EOF){
        fputc(n,fd_out);
    }

    fclose(fd);
    fclose(fd_out);
    return 0;
}