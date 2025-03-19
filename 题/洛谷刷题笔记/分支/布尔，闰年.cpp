#include<iostream>
using namespace std;


//熟悉逻辑运算符，if语句的多种格式，然后背下来手敲一遍AC
int main()
{
    int n;
    bool a=0,b=0,c=0,d=0;
    cin>>n;
    if(n%2==0&&(n>4&&n<=12))a=1;  //必须要符合两个条件
    if(n%2==0||(n>4&&n<=12))b=1;  //至少要符合一个条件
    if(n%2==0^(n>4&&n<=12))c=1;   //必须要只符合一个条件,这里的^是异或运算符
    if(n%2!=0&&(n<=4||n>12))d=1;  //必须要两个条件全都不符合;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;  //输出
    return 0;
}

//判断闰年
    
    bool runnian(int num){
    if ((num % 4 == 0 && num % 100 != 0) || num % 400 == 0) return true;
    else return false;
}