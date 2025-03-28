// 题目背景
// 某蒟蒻迷上了 “小书童”，有一天登陆时忘记密码了（他没绑定邮箱 or 手机），于是便把问题抛给了神犇你。

// 题目描述
// 蒟蒻虽然忘记密码，但他还记得密码是由一个字符串组成。密码是由原文字符串（由不超过 50 个小写字母组成）中每个字母向后移动 n 位形成的。z 的下一个字母是 a，如此循环。他现在找到了移动前的原文字符串及 n，请你求出密码。

// 输入格式
// 第一行：n。第二行：未移动前的一串字母。

// 输出格式
// 一行，是此蒟蒻的密码。

// 输入输出样例
// 输入 #1复制

// 1
// qwe
// 输出 #1复制

// rxf

// 原答案的问题：
// 1. 没有处理字母循环的问题，当字符+n超过'z'时，会变成非字母字符
// 2. 没有考虑n可能大于26的情况，直接加n会导致结果错误

#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    string str;
    cin >> n;
    cin.ignore();
    getline(cin,str);
    
    // 优化后的代码
    for(char &c : str) {
        // 计算移动后的字符位置
        int offset = (c - 'a' + n) % 26;  // 取模26保证在字母范围内
        c = 'a' + offset;  // 重新计算字符
    }
    
    cout << str << endl;
    return 0;
}

// 代码解释：
// 1. (c - 'a')：将字符转换为0-25的数字，a对应0，b对应1，...，z对应25
// 2. +n：加上移动的位数
// 3. %26：取模运算，确保结果在0-25之间，实现循环移动
// 4. 'a' + offset：将数字转换回对应的字母
// 这样处理可以完美解决：
// - 字母循环问题（z后面是a）
// - n大于26的情况（通过取模运算）
// - 保证结果始终是小写字母