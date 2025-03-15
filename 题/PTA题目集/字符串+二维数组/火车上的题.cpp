//  新浪微博上的一则趣闻，是瑞典斯德哥尔摩火车上的一道题，看上去是段伪代码：

// s = ''
// a = '1112031584'
// for (i = 1; i < length(a); i++) {
//   if (a[i] % 2 == a[i-1] % 2) {
//     s += max(a[i], a[i-1])
//   }
// }
// goto_url('www.multisoft.se/' + s)
// 其中字符串的 + 操作是连接两个字符串的意思。所以这道题其实是让大家访问网站 www.multisoft.se/112358（注意：比赛中千万不要访问这个网址！！！）。

// 当然，能通过上述算法得到 112358 的原始字符串 a 是不唯一的。本题就请你判断，两个给定的原始字符串，能否通过上述算法得到相同的输出？

// 输入格式：
// 输入为两行仅由数字组成的非空字符串，长度均不超过 10 
// 4
//  ，以回车结束。

// 输出格式：
// 对两个字符串分别采用上述斯德哥尔摩火车上的算法进行处理。如果两个结果是一样的，则在一行中输出那个结果；否则分别输出各自对应的处理结果，每个占一行。题目保证输出结果不为空。

// 输入样例 1：
// 1112031584
// 011102315849

// 输出样例 1：
// 112358
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 定义函数，根据算法生成字符串 s
string generateS(string a) {
    string s;
    for (size_t i = 1; i < a.length(); i++) {
        if ((a[i] - '0') % 2 == (a[i - 1] - '0') % 2) { // 判断奇偶性
            s += max(a[i], a[i - 1]); // 拼接较大的字符
        }
    }
    return s;
}

int main() {
    string a1, a2;
    getline(cin, a1); // 读取第一个字符串
    getline(cin, a2); // 读取第二个字符串

    string s1 = generateS(a1); // 生成 s1
    string s2 = generateS(a2); // 生成 s2

    if (s1 == s2) {
        cout << s1 << endl; // 如果 s1 和 s2 相同，输出 s1
    } else {
        cout << s1 << endl; // 否则分别输出 s1 和 s2
        cout << s2 << endl;
    }

    return 0;
}