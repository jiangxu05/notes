#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c;
    d=((a*b*c)/8)/1024;
    cout<<"水平分辨率为"<<a<<"， 垂直分辨率为"<<b<<"， 颜色位数为"<<c<<"的图像大小为"<<d<<"KB";
}

//abc字符串
#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin >>m>>n;
    int p=m%10+10*(n%10)+100*(m/10)+1000*(n/10)+10000*(m/100)+100000*(n/100);
    cout<<"p="<<p;
    return 0;
}

#include<iostream>
using namespace std;
int main (){
    int t1,t0,h1,h0;
    cin>>t1>>t0>>h1>>h0;
    cout<<"G="<<(t1-t0)/(h1-h0)*100.0<<"C"<<endl;
    cout<<"Dt="<<(h1-h0)/(t1-t0)*1.0<<"m"<<endl;
    return 0;
}


//
#include<iostream>
using namespace std;
int main (){
    int t1,t0,h1,h0;
    cin>>t1>>t0>>h1>>h0;
    double c=(double)(t1-t0)/(h1-h0);//这个方式
    double d=(double)(h1-h0)/(t1-t0);
    cout<<"G="<<c*100.0<<"C"<<endl;
    cout<<"Dt="<<d*1.0<<"m"<<endl;
    return 0;
}