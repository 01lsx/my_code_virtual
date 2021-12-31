#include<iostream>
using namespace std;
int main(){
    int i = 1;
    for(i = 1;i <= 100;i++){
        if(i % 7 == 0||i%10 == 7||i/ 10 == 7){
            cout<<"敲桌子"<<endl;
        }else
            cout<<i<<endl;
    }
    return 0;
}