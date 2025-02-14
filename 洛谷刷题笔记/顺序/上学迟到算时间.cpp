#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double s,v,m;
    int n,a,t,b;
    cin>>s>>v;
    n = 8* 60 + 24 * 60;
    t = ceil(s/v) + 10;     //ceil向上取整,ceil(1.1)=2,要用<cmath>
    n = n - t;
    if( n >= 60*24) 
    n -= 60*24;             //这里不加花括号,只有一句,不用加

    b = n % 60;             //得出出发分
    a = n / 60;             //得出出发时

    if(a < 10){
        if (b < 10) cout<<"0"<<a<<":"<<"0"<<b<<endl;
        else cout<<"0"<<a<<":"<<b<<endl;
    }
    else{
        if (b < 10) cout<<a<<":"<<"0"<<b<<endl;
        else cout<<a<<":"<<b<<endl;
    }
    return 0;
}
