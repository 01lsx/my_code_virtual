#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc,char *argv[]){
    struct stat sb;
    int ret = stat(argv[1],&sb);
    if(ret < 0){
        perror("stat error");
        exit(1);
    }
    /*
    if(S_ISREG(sb.st_mode)){
        printf("it is a regular file");
    }else if(S_ISDIR(sb.st_mode)){
        printf("it is a director file");
    }else if(S_ISFIFO(sb.st_mode)){
        printf("it is a pipe file");
    }else if(S_ISLNK(sb.st_mode)){
        printf("it is a link file");
    }else if(S_ISBLK(sb.st_mode)){
        printf("it is a block file");
    }else if(S_ISCHR(sb.st_mode)){
        printf("it is a character file");
    }else if(S_ISSOCK(sb.st_mode)){
        printf("it is a socket file");
    }
    printf("the size is %d",sb.st_size);
    */
    printf("the size is %d",sb.st_mode);
    switch(sb.st_mode & S_IFMT)
    {
        case S_IFREG: printf("regular file\n"); break;
        case S_IFDIR: printf("director file\n"); break;
        case S_IFCHR: printf("charactor file\n"); break;
        case S_IFBLK: printf("block file\n"); break;
        case S_IFIFO: printf("pipe file\n"); break;
        case S_IFLNK: printf("symbolic file\n"); break;
        case S_IFSOCK: printf("socket file\n"); break;
        default: printf("unknown file\n"); break;
    }
    return 0;

}