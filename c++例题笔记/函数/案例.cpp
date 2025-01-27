#include <iostream>
using namespace std;

int max (int a, int b);             // 函数声明, 也可以不写，但是要把函数定义放在main函数前面；声明可以写多次，定义只能写一次

int max (int a, int b) {            // 函数定义
    return a > b ? a : b;           // 三目运算符：如果a>b为真，返回a，否则返回b
}

int main() {
    int a = 10, b = 20;
    cout << "较大的数是：" << max(a, b) << endl;
    return 0;
}