#include <iostream>
#include <string>
using namespace std;
//i用来判断输入错误的次数
int main()
{
	int i=0;
	//初始化一个空字符串,s是密码字符串
	string pwd="",s="123456";
	cout<<"input password:";
	char c;
	while(true)
	{
		c=getchar();
		if(c!=13)//如果不是回车，就不断往string类型的pwd内添加c
		{	
			pwd=pwd+c;
			cout<<"*";
		}else{
			if(pwd==s)
			{
				cout<<"Yes!"<<endl;
				break;
			}else{
				++i;
				if(i==3){
					cout<<"Dead!";
					break;
				}else{
					cout<<"Wrong：Try Again!"<<endl;
					pwd="";
				}
			}
		}
	}
}