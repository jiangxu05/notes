// 你需要开发一款文字处理软件。最开始时输入一个字符串作为初始文档。可以认为文档开头是第 0 个字符。需要支持以下操作：

// 1 str：后接插入，在文档后面插入字符串 str，并输出文档的字符串；
// 2 a b：截取文档部分，只保留文档中从第 a 个字符起 b 个字符，并输出文档的字符串；
// 3 a str：插入片段，在文档中第 a 个字符前面插入字符串 str，并输出文档的字符串；
// 4 str：查找子串，查找字符串 str 在文档中最先的位置并输出；如果找不到输出 −1。
// 为了简化问题，规定初始的文档和每次操作中的 str 都不含有空格或换行。最多会有 q 次操作。

// 输入格式
// 第一行输入一个正整数 q，表示操作次数。

// 第二行输入一个字符串 str，表示最开始的字符串。

// 第三行开始，往下 q 行，每行表示一个操作，操作如题目描述所示。

// 输出格式
// 一共输出 q 行。

// 对于每个操作 1,2,3，根据操作的要求输出一个字符串。

// 对于操作 4，根据操作的要求输出一个整数。

// 输入输出样例
// 输入 #1复制

// 4
// ILove
// 1 Luogu
// 2 5 5
// 3 3 guGugu
// 4 gu
// 输出 #1复制

// ILoveLuogu
// Luogu
// LuoguGugugu
// 3
#include <iostream>
#include <string>
using namespace std;

int main() {
    int q;
    string str;
    cin >> q >> str;  // 读取操作次数和初始字符串
    
    while (q--) {
        int op;
        cin >> op;
        
        if (op == 1) {  // 后接插入
            string s;
            cin >> s;
            str += s;  // 在字符串末尾插入
            cout << str << endl;
        }
        else if (op == 2) {  // 截取部分
            int a, b;
            cin >> a >> b;
            str = str.substr(a, b);  // 从a开始截取b个字符
            cout << str << endl;
        }
        else if (op == 3) {  // 插入片段
            int a;
            string s;
            cin >> a >> s;
            str.insert(a, s);  // 在a位置插入字符串
            cout << str << endl;
        }
        else if (op == 4) {  // 查找子串
            string s;
            cin >> s;
            int pos = str.find(s);  // 查找子串位置
            cout << (pos == string::npos ? -1 : pos) << endl;
        }
    }
    
    return 0;
}
