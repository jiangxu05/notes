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
/*我的错误答案：
    int n;
    cin>>n;
    bool a = 0, b = 0;
    if (n%100==0 && n%400==0) {
        a = 1;
        cout << a <<endl;
    }
    if (n%4  ==0 && n%100!=0) {
        b = 1;
        cout << b <<endl;
    }
    else{
        cout << 0<<endl;
    }
    return 0;
} */
int main1() {
    int n;
    cin >> n;
    bool a = 0, b = 0;

    // 判断是否是闰年
    if (n % 100 == 0) {
        if (n % 400 == 0) {
            a = 1; // 能被400整除的年份是闰年
        }
    } 
    else {
        if (n % 4 == 0) {
            b = 1; // 不能被100整除且能被4整除的年份是闰年
        }
    }

    // 输出结果
    if (a || b) {
        cout << 1 << endl; // 如果是闰年，输出1
    } 
    else {
        cout << 0 << endl; // 如果不是闰年，输出0
    }

    return 0;
}
//背完再去手敲一遍