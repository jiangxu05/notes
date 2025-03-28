// 题目描述
// 凯凯刚写了一篇美妙的作文，请问这篇作文的标题中有多少个字符？ 注意：标题中可能包含大、小写英文字母、数字字符、空格和换行符。统计标题字符数时，空格和换行符不计算在内。

// 输入格式
// 输入文件只有一行，一个字符串 s。

// 输出格式
// 输出文件只有一行，包含一个整数，即作文标题的字符数（不含空格和换行符）。

// 输入输出样例
// 输入 #1复制

// 234 
// 输出 #1复制

// 3
// 输入 #2复制

// Ca 45 
// 输出 #2复制

// 4
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);  // 读取整行输入，包括空格
    
    int count = 0;
    for (char c : s) {
        if (!isspace(c)) {  // 使用isspace判断是否为空白字符（包括空格和换行）
            count++;  // 如果不是空白字符，则计数加1
        }
    }
    
    cout << count << endl;
    return 0;
}
