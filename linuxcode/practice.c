#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>

#define PATH_LEN 256

void fetchdir(char *dir,void (*func)(char *)){
    
    struct dirent *sdp;
    DIR *dp;
    char *name[PATH_LEN];

    if(dp = opendir(dir) == NULL){
        perror("opendir error");
        exit(1);
    }

    while((sdp = readdir(dp)) != NULL){
        if(strcmp(sdp->d_name,".") == 0 || strcmp(sdp->d_name,"..") == 0){
            continue;
        }
        if(strlen(dir)+strlen(sdp->d_name)+2 > PATH_LEN){
            fprintf(stderr,"name %s %s too long",dir,sdp->d_name);
        }else{
            sprintf(name,"%s/%s",dir,sdp->d_name);
            (*func)(name);
        }
    }

    closeddir(dp);
}

void isfile(char *name){
    struct stat sbuf;
    if(stat(name,&sbuf) == -1){
        perror("stat error");
        exit(1);
    }

    if((sbuf.st_mode & S_IFMT) == S_IFDIR){
        fetchdir(name,isfile);
    }
    printf("%8lf %s",sbuf.st_size,name);
}

int main(int argc,char *argv[]){
    if(argc == 1){
        isfile(".");
    }else{
        while(--argc > 0){
        isfile(*++argv);
        }
    }
}