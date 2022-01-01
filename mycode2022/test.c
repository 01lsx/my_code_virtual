#include<stdio.h>

void add(int *a){
    a[0] = 1;
    a[1] = 2;
}

int main(){
    int a[2] = {0,0};
    add(a);
    for(int i = 0;i < 2;++i){
        printf("%d",a[i]);
    }

}