// 输入一个长度不超过 100 且不包括空格的字符串。要求将该字符串中的所有小写字母变成大写字母并输出。

// 输入格式
// 输入一行，一个字符串。

// 输出格式
// 输出一个字符串，即将原字符串中的所有小写字母转化为大写字母。
#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 32;
    }
    cout << s << endl;
    return 0;
}