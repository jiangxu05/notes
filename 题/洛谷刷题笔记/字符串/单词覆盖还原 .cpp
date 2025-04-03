// 题目描述
// 我有一个长度为 l 的字符串，最开始时，这个字符串由 l 个句号（.）组成。

// 我在这个字符串中，将多次把 boy 或者 girl 两单词，依次贴到这个字符串中。

// 后贴上单词，会覆盖之前贴上的单词，或者覆盖句号。最终，每个单词至少有一个字符没有被覆盖。

// 请问，一共贴有几个 boy 几个 girl？

// 输入格式
// 一行被反复贴有 boy 和 girl 两单词的字符串。

// 输出格式
// 两行，两个整数。第一行为 boy 的个数，第二行为 girl 的个数。

// 输入输出样例
// 输入 #1复制

// ......boyogirlyy......girl.......
// 输出 #1复制

// 4
// 2
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    int boyCount = 0, girlCount = 0;
    int len = s.length();
    
    for (int i = 0; i < len; i++) {  // 改为逐字符遍历
        // 检查boy（允许部分覆盖）
        if (i+2 < len && (s[i]=='b'||s[i+1]=='o'||s[i+2]=='y')) {
            boyCount++;
        }
        // 检查girl（允许部分覆盖）
        if (i+3 < len && (s[i]=='g'||s[i+1]=='i'||s[i+2]=='r'||s[i+3]=='l')) {
            girlCount++;
        }
    } 
    
    cout << boyCount << endl;
    cout << girlCount << endl;
    return 0;
}