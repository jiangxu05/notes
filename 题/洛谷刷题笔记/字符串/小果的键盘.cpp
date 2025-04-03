// 小果有一个只有两个键的键盘。

// 题目描述
// 一天，她打出了一个只有这两个字符的字符串。当这个字符串里含有 VK 这个字符串的时候，小果就特别喜欢这个字符串。所以，她想改变至多一个字符（或者不做任何改变）来最大化这个字符串内 VK 出现的次数。给出原来的字符串，请计算她最多能使这个字符串内出现多少次 VK（只有当 V 和 K 正好相邻时，我们认为出现了 VK。）

// 输入格式
// 第一行给出一个数字 n，代表字符串的长度。

// 第二行给出一个字符串 s。

// 输出格式
// 第一行输出一个整数代表所求答案。

// 输入输出样例
// 输入 #1复制

// 2
// VK
// 输出 #1复制

// 1
// 输入 #2复制

// 2
// VV
// 输出 #2复制

// 1
// 输入 #3复制

// 1
// V
// 输出 #3复制

// 0
// 输入 #4复制

// 20
// VKKKKKKKKKVVVVVVVVVK
// 输出 #4复制

// 3
// 输入 #5复制

// 4
// KVKV
// 输出 #5复制

// 1
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int originalVKCount = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'V' && s[i + 1] == 'K') {
            originalVKCount++;
        }
    }

    // 尝试改变每个字符，看是否可以增加 VK 的数量
    int maxVKCount = originalVKCount;
    for (int i = 0; i < n; ++i) {
        char originalChar = s[i];
        // 尝试将当前字符改为 'V' 或 'K'
        for (char c : {'V', 'K'}) {
            if (s[i] != c) {
                s[i] = c;
                int modifiedVKCount = 0;
                for (int j = 0; j < n - 1; ++j) {
                    if (s[j] == 'V' && s[j + 1] == 'K') {
                        modifiedVKCount++;
                    }
                }
                maxVKCount = max(maxVKCount, modifiedVKCount);
                s[i] = originalChar; // 恢复原字符
            }
        }
    }

    cout << maxVKCount << endl;
    return 0;
}
