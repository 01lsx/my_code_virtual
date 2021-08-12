#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    char msg[] = "it is a test for lseek\n";
    char ch;
    int n,fd;

    fd = open("lseek.txt",O_RDWR|O_CREAT,0644);
    if(fd < 0){
        perror("open error");
        exit(1);
    }

    write(fd,msg,strlen(msg)); //向文件中写内容，完成后文件的读写指针在文件的末尾。
    //lseek(fd,0,SEEK_SET) // 修改文件读写指针的位置，使其位于文件开头。
    while((n = read(fd,&ch,1)) != 0){
        if(n < 0){
            perror("read error");
            exit(1);
        }
        write(STDOUT_FILENO,&ch,1); //将文件中的内容按字节的顺序打印到屏幕上
    }
    close(fd);
    sleep(2);

}