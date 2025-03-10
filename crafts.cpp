//- 例如 679 的持续性就是 5，因为我们从 679 开始，得到 6×7×9=378，随后得到 3×7×8=168、1×6×8=48、4×8=32，最后得到 3×2=6，一共用了 5 步。
//- 输入在一行中给出两个正整数 a 和 b（1≤a≤b≤10^9且 (b−a)<10^3），为给定区间的两个端点。
//- 首先在第一行输出区间 [a,b] 内整数最长的持续性。随后在第二行中输出持续性最长的整数。如果这样的整数不唯一，则按照递增序输出，数字间以 1 个空格分隔，行首尾不得有多余空格。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 计算一个数的持续性
int chixuxing(int num) {
    int steps = 0;
    while (num >= 10) { // 当 num 不是单个数字时继续
        int jieguo = 1;
        while (num > 0) { // 计算各位数字的乘积
            jieguo *= num % 10;
            num /= 10;
        } //反正就记住除10去掉个位，模10取个位
        num = jieguo; // 更新 num 为乘积
        steps++; // 增加步骤数
    }
    return steps;
}

int main() {
    int a, b;
    cin >> a >> b; // 输入区间 [a, b]
    int maxLen = 0; // 记录最大持续性
    vector<int> zuidachixushu; // 记录具有最大持续性的数

    for (int i = a; i <= b; i++) {
        int chixushu = chixuxing(i); // 计算当前数的持续性
        if (chixushu > maxLen) {
            maxLen = chixushu; // 更新最大持续性
            zuidachixushu.clear(); // 清空之前的记录
            zuidachixushu.push_back(i); // 添加当前数
        } else if (chixushu == maxLen) {
            zuidachixushu.push_back(i); // 如果持续性相同，添加到记录中
        }
    }

    // 输出结果
    cout << maxLen << endl; // 输出最大持续性
    for (int i = 0; i < zuidachixushu.size(); i++) {
        cout << zuidachixushu[i];
        if (i != zuidachixushu.size() - 1) {//最后一个数后面不加空格
            cout << " "; // 数字间用空格分隔
        }
    }
    return 0;
}