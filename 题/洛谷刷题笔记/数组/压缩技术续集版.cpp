// 题目描述
// 设某汉字由 N×N 的 0 和 1 的点阵图案组成。
// 我们依照以下规则生成压缩码。连续一组数值：从汉字点阵图案的第一行第一个符号开始计算，按书写顺序从左到右，由上至下。
//第一个数表示连续有几个 0，第二个数表示接下来连续有几个 1，第三个数再接下来连续有几个 0，第四个数接着连续几个 1，以此类推……
// 例如: 以下汉字点阵图案：

// 0001000
// 0001000
// 0001111
// 0001000
// 0001000
// 0001000
// 1111111
// 对应的压缩码是： 7 3 1 6 1 6 4 3 1 6 1 6 1 3 7 （第一个数是 N ,其余各位表示交替表示0和1 的个数，压缩码保证 N×N= 交替的各位数之和）

// 输入格式
// 汉字点阵图（点阵符号之间不留空格）。

// 输出格式
// 输出一行，压缩码。

// 输入输出样例
// 输入 #1复制

// 0001000
// 0001000
// 0001111
// 0001000
// 0001000
// 0001000
// 1111111
// 输出 #1复制

// 7 3 1 6 1 6 4 3 1 6 1 6 1 3 7
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // 读入点阵大小N并存储点阵
    string diyihang;
    cin >> diyihang;
    int dianzheng_daxiao = diyihang.length();
    
    // 创建二维数组存储点阵
    vector<vector<char>> dianzheng(dianzheng_daxiao, vector<char>(dianzheng_daxiao));
    dianzheng[0] = vector<char>(diyihang.begin(), diyihang.end());
    
    // 读入剩余行
    for(int i = 1; i < dianzheng_daxiao; i++) {
        string hang;
        cin >> hang;
        dianzheng[i] = vector<char>(hang.begin(), hang.end());
    }
    
    // 输出点阵大小
    cout << dianzheng_daxiao << " ";
    
    // 计算压缩码
    int lianxu_geshu = 0;  // 记录连续的0或1的个数
    char dangqian_zifu = '0';  // 当前应该计数的字符(0或1)
    
    // 按照从左到右,从上到下的顺序遍历
    for(int i = 0; i < dianzheng_daxiao; i++) {
        for(int j = 0; j < dianzheng_daxiao; j++) {
            if(dianzheng[i][j] == dangqian_zifu) {
                lianxu_geshu++;
            } else {
                // 输出之前累积的连续个数
                cout << lianxu_geshu << " ";
                // 重置计数器并切换当前字符
                lianxu_geshu = 1;
                dangqian_zifu = dianzheng[i][j];
            }
        }
    }
    // 输出最后一组连续数
    cout << lianxu_geshu << endl;
    
    return 0;
}

/*
本题的难点和关键点:

1. 输入处理
- 第一行需要特殊处理来获取点阵大小
- 使用string来读取每一行,避免空格问题

2. 压缩算法的实现
- 需要记录当前应该统计的字符(0或1)
- 需要计数连续出现的次数
- 遇到不同字符时输出计数并重置

3. 遍历顺序
- 按照从左到右,从上到下的顺序
- 使用双重循环实现

4. 输出格式
- 第一个数是点阵大小N
- 后面的数交替表示0和1的连续个数
- 最后一个数需要特别处理

5. 数据结构选择
- 使用vector<vector<char>>存储点阵
- 方便访问和处理二维数据
*/
