// 给定一个数，请将该数各个位上数字反转得到一个新数。

// 这次与 NOIp2011 普及组第一题不同的是：这个数可以是小数，分数，百分数，整数。整数反转是将所有数位对调；小数反转是把整数部分的数反转，再将小数部分的数反转，不交换整数部分与小数部分；分数反转是把分母的数反转，再把分子的数反转，不交换分子与分母；百分数的分子一定是整数，百分数只改变数字部分。整数新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零；小数新数的末尾不为 0（除非小数部分除了 0 没有别的数，那么只保留1个 0）；分数不约分，分子和分母都不是小数（约分滴童鞋抱歉了，不能过哦。输入数据保证分母不为 0），本次没有负数。

// 题目描述
// 给定一个数，请将该数各个位上数字反转得到一个新数。

// 这次与 NOIp2011 普及组第一题不同的是：这个数可以是小数，分数，百分数，整数。

// 整数反转是将所有数位对调。

// 小数反转是把整数部分的数反转，再将小数部分的数反转，不交换整数部分与小数部分。

// 分数反转是把分母的数反转，再把分子的数反转，不交换分子与分母。

// 百分数的分子一定是整数，百分数只改变数字部分。

// 输入格式
// 一个实数 s

// 输出格式
// 一个实数，即 s 的反转数

// 输入输出样例
// 输入 #1复制

// 5087462
// 输出 #1复制

// 2647805
// 输入 #2复制

// 600.084
// 输出 #2复制

// 6.48
// 输入 #3复制

// 700/27
// 输出 #3复制

// 7/72
// 输入 #4复制

// 8670%
// 输出 #4复制

// 768%
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 反转字符串，并去除前导零
string reverseStr(string s) {
    reverse(s.begin(), s.end());
    // 去除前导零
    s.erase(0, s.find_first_not_of('0'));
    // 如果全部是0，保留一个0
    if (s.empty()) s = "0";
    return s;
}

int main() {
    string s;
    cin >> s;
    
    // 判断输入类型
    if (s.find('.') != string::npos) {  // 小数
        int pos = s.find('.');
        string intPart = s.substr(0, pos);
        string decPart = s.substr(pos + 1);
        // 反转整数部分和小数部分
        string newInt = reverseStr(intPart);
        string newDec = reverseStr(decPart);
        // 去除小数部分末尾的0

        newDec.erase(newDec.find_last_not_of('0') + 1);//注意这个加一

        if (newDec.empty()) newDec = "0";  // 如果小数部分全为0，保留一个0
        
        cout << newInt << "." << newDec << endl;
    }
    else if (s.find('/') != string::npos) {  // 分数
        int pos = s.find('/');
        string numerator = s.substr(0, pos);
        string denominator = s.substr(pos + 1);
        // 反转分子和分母
        string newNum = reverseStr(numerator);
        string newDen = reverseStr(denominator);
        cout << newNum << "/" << newDen << endl;
    }
    else if (s.find('%') != string::npos) {  // 百分数
        string num = s.substr(0, s.length() - 1);
        string newNum = reverseStr(num);
        cout << newNum << "%" << endl;
    }
    else {  // 整数
        string newNum = reverseStr(s);
        cout << newNum << endl;
    }
    
    return 0;
}
