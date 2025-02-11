#include <iostream>
using namespace std;
//指针间接访问内存；内存编号从0开始
int main() {
    int a = 10, b = 20;             //指针定义的语法：数据类型 *指针变量名 
    int *p1 = &a, *p2 = &b;         // 定义指针变量p1和p2，分别指向a和b
    cout << "a = " << a << ", b = " << b << endl;
    cout << "*p1 = " << *p1 << ", *p2 = " << *p2 << endl;//指针变量前加*，表示取出指针变量指向的内存中的值 输出：a = 10, b = 20, *p1 = 10, *p2 = 20
    cout << "p1 = " << p1 << ", p2 = " << p2 << endl;   //指针变量前不加*，表示取出指针变量本身的值，即内存编号 输出 p1 = 0x7ffebc1b3b7c, p2 = 0x7ffebc1b3b78
    cout << "sizeof(int *) = " << sizeof(int *) << endl; //输出指针变量的大小，64位系统下为8字节
    return 0;
} 
//空指针：指针变量指向内存编号为0的内存空间，表示不指向任何有效的内存空间
//空指针的使用：空指针不能访问内存中的值，但是可以给指针变量赋值
int main() {
    int *p = NULL;                  //定义空指针
    cout << "p = " << p << endl;    //输出p = 0
    //cout << "*p = " << *p << endl;  //空指针不能访问内存中的值，会报错
    p = (int *)0x7ffebc1b3b7c;      //给指针变量赋值
    cout << "p = " << p << endl;    //输出p = 0x7ffebc1b3b7c
    return 0;
}
//野指针：指针变量指向非法的内存空间，可能会导致程序崩溃
int main() {
    int *p = (int *)0x7ffebc1b3b7c; //定义野指针
    cout << "p = " << p << endl;    //输出p = 0x7ffebc1b3b7c    
    //cout << "*p = " << *p << endl;  //野指针不能访问内存中的值，会报错
    return 0;
}
//const修饰指针变量：const修饰指针变量，表示指针变量指向的内存空间不能修改
int main() {
    int a = 10, b = 20;
    const int *p = &a;              //定义指针变量p，指向a，且a的值不能修改
    // *p = 20;                     //错误，不能修改*p指向的内存空间的值
    p = &b;                         //正确，可以修改p指向的内存空间
    cout << "*p = " << *p << endl;  //输出*p = 20
    return 0;
}
//指针常量：指针常量是指针变量本身不能修改，但是指针变量指向的内存空间的值可以修改
int main() {
    int a = 10, b = 20;
    int *const p = &a;              //定义指针常量p，指向a，且p的值不能修改
    // p = &b;                      //错误，不能修改指针常量p的值
    *p = 20;                        //正确，可以修改*p指向的内存空间的值
    cout << "*p = " << *p << endl;  //输出*p = 20
    return 0;
}