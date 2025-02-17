#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c;
    d=((a*b*c)/8)/1024;
    cout<<"水平分辨率为"<<a<<"， 垂直分辨率为"<<b<<"， 颜色位数为"<<c<<"的图像大小为"<<d<<"KB";
}