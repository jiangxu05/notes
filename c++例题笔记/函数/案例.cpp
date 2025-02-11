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

//值传递：
// void swap(int a, int b) {           //定义函数swap，参数为整型变量a和b
//     int temp = a;                   //定义临时变量temp，存储a的值
//     a = b;                          //将b的值赋给a
//     b = temp;                       //将temp的值赋给b
// }
// int main() {
//     int a = 10, b = 20;
//     cout << "a = " << a << ", b = " << b << endl; //输出a = 10, b = 20
//     swap(a, b);                     //调用函数swap，传入a和b的值
//     cout << "a = " << a << ", b = " << b << endl; //输出a = 10, b = 20，
//     return 0;
// }
// 要想a，b交换应该这样写：
// void swap(int &a, int &b) {         //定义函数swap，参数为整型变量a和b的引用
//     int temp = a;                   //定义临时变量temp，存储a的值
//     a = b;                          //将b的值赋给a
//     b = temp;                       //将temp的值赋给b
// }
// int main() {
//     int a = 10, b = 20;
//     cout << "a = " << a << ", b = " << b << endl; //输出a = 10, b = 20
//     swap(a, b);                     //调用函数swap，传入a和b的引用   
//     cout << "a = " << a << ", b = " << b << endl; //输出a = 20, b = 10
//     return 0;
// }