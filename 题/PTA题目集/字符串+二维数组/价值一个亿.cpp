// 本题要求你实现一个稍微更值钱一点的 AI 英文问答程序，规则是：
// 无论用户说什么，首先把对方说的话在一行中原样打印出来；
// 消除原文中多余空格：把相邻单词间的多个空格换成 1 个空格，把行首尾的空格全部删掉，把标点符号前面的空格删掉；
// 把原文中所有大写英文字母变成小写，除了 I；
// 把原文中所有独立的 can you、could you 对应地换成 I can、I could—— 这里“独立”是指被空格或标点符号分隔开的单词；
// 把原文中所有独立的 I 和 me 换成 you；
// 把原文中所有的问号 ? 换成惊叹号 !；
// 在一行中输出替换后的句子作为 AI 的回答。
// 输入格式：
// 输入首先在第一行给出不超过 10 的正整数 N，随后 N 行，每行给出一句不超过 1000 个字符的、以回车结尾的用户的对话，对话为非空字符串，仅包括字母、数字、空格、可见的半角标点符号。

// 输出格式：
// 按题面要求输出，每个 AI 的回答前要加上 AI: 和一个空格。

// 输入样例：
// 6
// Hello ?
//  Good to chat   with you
// can   you speak Chinese?
// Really?
// Could you show me 5
// What Is this prime? I,don 't know

// 输出样例：
// Hello ?
// AI: hello!
//  Good to chat   with you
// AI: good to chat with you
// can   you speak Chinese?
// AI: I can speak chinese!
// Really?
// AI: really!
// Could you show me 5
// AI: I could show you 5
// What Is this prime? I,don 't know
// AI: what Is this prime! you,don't know
#include <iostream>
#include <string>
#include <sstream>  // stringstream用于字符串分割
using namespace std;

// 处理标点符号前的空格
string quchukongge(string s) {
    string jg = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ' && i+1 < s.length() && (s[i+1] == ',' || s[i+1] == '.' || s[i+1] == '?' || s[i+1] == '!'))
            continue;
        jg += s[i];
    }
    return jg;
}

// 处理多余空格
string guolv(string s) {
    // stringstream可以像cin那样读取字符串中的内容
    // 会自动以空格为分隔符分割字符串
    stringstream ss(s);  
    string danci, jg = "";
    bool diyi = true;
    // 用>>运算符从stringstream中读取单词,类似cin
    while(ss >> danci) {  
        if(!diyi) jg += " ";
        jg += danci;
        diyi = false;
    }
    return jg;
}

// 处理大小写和替换
string tihuan(string s) {
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'I')
            s[i] = tolower(s[i]);
    }
    
    stringstream ss(s);
    string danci, jg = "";
    bool diyi = true;
    while(ss >> danci) {
        if(!diyi) jg += " ";
        if(danci == "can" && ss.peek() == ' ') {  // peek()查看下一个字符但不读取
            string next;
            ss >> next;
            if(next == "you") {
                jg += "I can";
                diyi = false;
                continue;
            }
            jg += "can " + next;
        }
        else if(danci == "could" && ss.peek() == ' ') {
            string next;
            ss >> next;
            if(next == "you") {
                jg += "I could";
                diyi = false;
                continue;
            }
            jg += "could " + next;
        }
        else if(danci == "I" || danci == "me")
            jg += "you";
        else
            jg += danci;
        diyi = false;
    }
    return jg;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();  // 忽略换行符
    
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        cout << s << endl;
        
        s = guolv(s);  // 先处理多余空格
        s = quchukongge(s);  // 处理标点前空格
        s = tihuan(s);  // 处理替换和大小写
        
        // 替换问号
        for(int j = 0; j < s.length(); j++) {
            if(s[j] == '?') s[j] = '!';
        }
        
        cout << "AI: " << s << endl;
    }
    return 0;
}





