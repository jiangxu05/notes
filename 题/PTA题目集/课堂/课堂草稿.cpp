// 九九乘法表
//c++中右对齐是：setw(n) 的参数必须是非负整数，设置的是最小字段宽度

// 对齐方向由格式标志控制，与 setw 参数正负无关：

// left：左对齐（默认适用于字符串）

// right：右对齐（默认适用于数字）

// internal：符号左对齐，数值右对齐
#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= i; j++){
            cout << i <<"*"<<j<<"="<<left<<setw(2)<<i*j<<" ";
        }
        cout << endl;
    }
}


//打印棱形
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    // 打印上半部分（包括中间行）
    for(int i = 0; i < n / 2 + 1; i++){
        // 打印空格：每行空格数 = 总行数/2 - 当前行号
        for(int j = 0; j < n / 2 - i; j++){
            cout << " ";
        }
        // 打印星号：每行星号数 = 2*当前行号 + 1
        for(int j = 0; j < 2 * i + 1; j++){
            cout << "*";
        }
        cout << endl;
    }
    
    // 打印下半部分
    for(int i = n / 2 - 1; i >= 0; i--){
        // 打印空格：与上半部分对称,,,注意这个 对称哈。。。。。。
        for(int j = 0; j < n / 2 - i; j++){
            cout << " ";
        }
        // 打印星号：与上半部分对称
        for(int j = 0; j < 2 * i + 1; j++){
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}
//求1000以内的完数。说明：一个数如果恰好等于它的因子之和（自身除外），则称该数为完数，例如6=1+2+3，28=1+2+4+7+14，则6和28都为完数。

// 输入格式:
// 无

// 输出格式:
// 逐行每个完数的因子累加形式的分解式，每个完数占一行，格式为“完数 = 因子1 + 因子2 + ... + 因子k”，其中完数和因子均按递增顺序给出。

// 输入样例:
// 无
// 部分输出样例:
// 6=1+2+3
// 28=1+2+4+7+14
// ...
#include <iostream>
#include <vector>
using namespace std;

// 判断是否为完数，并收集所有真因子

//真因子定义：能整除 num 且小于 num 的正整数。

//最大真因子范围：
//对于任意 num > 2，其最大真因子不会超过 num/2。
bool isPerfect(int num, vector<int>& factors) {
    factors.clear();
    int sum = 0;
    for (int i = 1; i <= num / 2; ++i) { // 遍历到num/2即可
        if (num % i == 0) {
            factors.push_back(i);
            sum += i;
        }
    }
    return sum == num;
}

int main() {
    vector<int> factors;
    for (int i = 6; i <= 1000; ++i) { // 完数最小为6
        if (isPerfect(i, factors)) {
            // 格式化输出
            cout << i << "=";
            for (size_t j = 0; j < factors.size(); ++j) {
                cout << factors[j];
                if (j != factors.size() - 1) {
                    cout << "+";
                }
            }
            cout << endl;
        }
    }
    return 0;
}


//
// 打印沙漏：本题要求你写个程序把给定的符号打印成沙漏的形状。所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

// 输入格式:
// 输入在一行给出1个正整数N（<=1000）和一个符号，中间以空格分隔。

// 输出格式:
// 首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

// 输入样例:
// 19 *
// 输出样例:
// *****
//  ***
//   *
//  ***
// *****
// 2

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    char c;
    cin >> N >> c;
    
    // 计算最大行数
    // 沙漏的总符号数公式为：2*k^2 - 1 <= N
    // 其中k为最大行数的一半（向上取整）
    int k = sqrt((N + 1) / 2);
    int maxLine = 2 * k - 1;  // 最大行数
    int used = 2 * k * k - 1; // 使用的符号数
    
    // 打印上半部分（包括中间行）
    for(int i = 0; i < k; i++) {
        // 打印空格
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        // 打印符号
        for(int j = 0; j < maxLine - 2 * i; j++) {
            cout << c;
        }
        cout << endl;
    }
    
    // 打印下半部分
    for(int i = k - 2; i >= 0; i--) {
        // 打印空格
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        // 打印符号
        for(int j = 0; j < maxLine - 2 * i; j++) {
            cout << c;
        }
        cout << endl;
    }
    
    // 输出剩余符号数
    cout << N - used << endl;
    
    return 0;
}
// 数学推导：
// 设层数为k（上半部分层数），则：
// 上半部分符号总数 = (2k-1) + (2k-3) + ... +3 +1 = k²
// 整个沙漏符号数 = 2(k² -1) +1 = 2k² -1

