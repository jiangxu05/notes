// 题目描述
// 笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！

// 这种方法的具体描述如下：假设 maxn 是单词中出现次数最多的字母的出现次数，minn 是单词中出现次数最少的字母的出现次数，如果 maxn−minn 是一个质数，那么笨小猴就认为这是个 Lucky Word，这样的单词很可能就是正确的答案。

// 输入格式
// 一个单词，其中只可能出现小写字母，并且长度小于 100。

// 输出格式
// 共两行，第一行是一个字符串，假设输入的的单词是 Lucky Word，那么输出 Lucky Word，否则输出 No Answer；

// 第二行是一个整数，如果输入单词是 Lucky Word，输出 maxn−minn 的值，否则输出 0。

// 输入输出样例
// 输入 #1复制

// error
// 输出 #1复制

// Lucky Word
// 2
#include<iostream>
#include<string>
#include<climits>
using namespace std;

bool isprime(int n ){
    if(n <= 1) return false;
    for(int i = 2; i*i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    string word;
    cin >> word;
    int maxn = 0, minn = INT_MAX;
    int count[26] = {0};
    for(char c : word){
        count[c - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(count[i] > maxn) maxn = count[i];
        if(count[i] > 0 && count[i] < minn) minn = count[i];
    }
    if(isprime(maxn - minn)){
        cout << "Lucky Word" << endl;
        cout << maxn - minn << endl;
    }
    else{
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    return 0;
}
//过仔细分析，问题出在 minn 的初始化逻辑 上。当单词中所有字母的出现次数都相同时，
//代码会错误地将 minn 保持为初始值 100，导致计算出现负数差。
