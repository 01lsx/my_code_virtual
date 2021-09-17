#include<iostream>
using namespace std;
int main(){
    int num = 100;
    int a,b,c,i = 1;
    do{
        a = num % 10;//个位
        b = num/10%10;//十位
        c = num/100;//百位
        if(a*a*a + b*b*b + c*c*c == num){
            cout<<"第"<<i<<"个水仙花数："<<num<<endl;
            i++;
        }
        num++;    
    }while(num<1000);
    return 0;

}