#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

#define PATH_LEN 46

void fetchdir(const char *dir,void (*func)(char *)){ //该函数被调用，则已被判定为目录
    char name[PATH_LEN];
    struct dirent *sdp;
    DIR *dp;

    if((dp = opendir(dir)) == NULL){
        perror("fetchdir can`t open");
        return;
    }

    while((sdp = readdir(dp)) != NULL){
        if(strcmp(sdp->d_name,".") == 0 || strcmp(sdp->d_name,"..") == 0){
            continue;//防止出现无限递归
        }
        if(strlen(dir)+strlen(sdp->d_name)+2 > sizeof(name)){
            fprintf(stderr,"name %s %s too long\n",dir,sdp->d_name);
        }else{ 
            sprintf(name,"%s/%s",dir,sdp->d_name);
            (*func)(name);
            //isfile(name)
       }
    }
    closedir(dp);
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

    printf("%8ld %s\n",sbuf.st_size,name);
}

int main(int argc,char *argv[]){
    if(argc == 1){
        isfile(".");
    }else{
        while(--argc > 0){  //可以一次查询多个目录
            isfile(*++argv); //循环调用该函数处理各个命令行传入的目录
        }
        return 0;
    }
}
