#include<iostream>
#include<ctime>
using namespace std;
int main(){
    //添加随机数种子，利用当前系统时间生成随机数，防止每次随机数都一样
    srand(time(NULL));
    int number1 = rand()%10+1;
    int number2 = 0;
    while(1){
        cin>>number2;
        //int i = rand()%10+1;
        //printf("%d",i);
        //char ch = getchar();
        if(number2 < number1){
            cout<<"小于目标数"<<endl;
        }else if(number2 > number1){
            cout<<"大于目标数"<<endl;
        }else{
            cout<<"恭喜你猜对了！"<<endl;
            break;
        }   
    }
    return 0;
}