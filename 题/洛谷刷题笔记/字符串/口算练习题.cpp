// 王老师正在教简单算术运算。细心的王老师收集了 i 道学生经常做错的口算题，并且想整理编写成一份练习。 编排这些题目是一件繁琐的事情，为此他想用计算机程序来提高工作效率。王老师希望尽量减少输入的工作量，比如 5+8 的算式最好只要输入 5 和 8，输出的结果要尽量详细以方便后期排版的使用，比如对于上述输入进行处理后输出 5+8=13 以及该算式的总长度 6。王老师把这个光荣的任务交给你，请你帮他编程实现以上功能。

// 输入格式
// 第一行一个整数 i。

// 接着的 i 行为需要输入的算式，每行可能有三个数据或两个数据。

// 若该行为三个数据则第一个数据表示运算类型，a 表示加法运算，b 表示减法运算，c 表示乘法运算，接着的两个数据表示参加运算的运算数。

// 若该行为两个数据，则表示本题的运算类型与上一题的运算类型相同，而这两个数据为运算数。

// 输出格式
// 输出 2×i 行。对于每个输入的算式，输出完整的运算式及结果，第二行输出该运算式的总长度。

// 输入输出样例
// 输入 #1复制

// 4
// a 64 46
// 275 125
// c 11 99
// b 46 64
// 输出 #1复制

// 64+46=110
// 9
// 275+125=400
// 11
// 11*99=1089
// 10
// 46-64=-18
// 9
#include<iostream>
#include<string>
using namespace std;

int main() {
    int i;
    cin >> i;
    char lastOp = 'a'; // 默认初始化为加法，因为第一个算式必须指定运算符
    
    while(i--) {
        string s1, s2;
        char op;
        cin >> s1;
        
        // 判断输入的是运算符还是数字
        if(s1 == "a" || s1 == "b" || s1 == "c") {
            op = s1[0];  // 获取运算符
            cin >> s1 >> s2;  // 读取两个操作数
            lastOp = op;  // 更新最后使用的运算符
        } else {
            cin >> s2;  // 只读取第二个操作数
            op = lastOp;  // 使用上次的运算符
        }
        
        // 将字符串转换为数字
        int num1 = stoi(s1);
        int num2 = stoi(s2);
        int result;
        string equation;
        
        // 根据运算符进行计算
        switch(op) {
            case 'a':
                result = num1 + num2;
                equation = to_string(num1) + "+" + to_string(num2) + "=" + to_string(result);
                break;
            case 'b':
                result = num1 - num2;
                equation = to_string(num1) + "-" + to_string(num2) + "=" + to_string(result);
                break;
            case 'c':
                result = num1 * num2;
                equation = to_string(num1) + "*" + to_string(num2) + "=" + to_string(result);
                break;
        }
        
        // 输出结果
        cout << equation << endl;
        cout << equation.length() << endl;
    }
    
    return 0;
}

