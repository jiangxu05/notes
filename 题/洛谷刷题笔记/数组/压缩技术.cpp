// 设某汉字由 N×N 的 0 和 1 的点阵图案组成。
// 我们依照以下规则生成压缩码。连续一组数值：从汉字点阵图案的第一行第一个符号开始计算，按书写顺序从左到右，由上至下。第一个数表示连续有几个 0，第二个数表示接下来连续有几个 1，第三个数再接下来连续有几个 0，第四个数接着连续几个 1，以此类推……
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
// 数据输入一行，由空格隔开的若干个整数，表示压缩码。

// 其中，压缩码的第一个数字就是 N，表示这个点阵应当是 N×N 的大小。

// 接下来的若干个数字，含义如题目描述所述。

// 输出格式
// 输出一个 N×N 的 01 矩阵，表示最后的汉字点阵图（点阵符号之间不留空格）。

// 输入输出样例
// 输入 #1复制

// 7 3 1 6 1 6 4 3 1 6 1 6 1 3 7
// 输出 #1复制

// 0001000
// 0001000
// 0001111
// 0001000
// 0001000
// 0001000
// 1111111
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int daxiao; // 点阵大小N
    cin >> daxiao;
    
    vector<int> yasuo; // 存储压缩码
    int shuzi;
    while(cin >> shuzi) {
        yasuo.push_back(shuzi);
    }
    
    // 创建点阵数组
    vector<vector<int>> dianzheng(daxiao, vector<int>(daxiao));
    
    int hang = 0, lie = 0; // 当前位置
    int dangqian = 0; // 当前是0还是1
    
    // 遍历压缩码,从第二个数开始
    for(int i = 1; i < yasuo.size(); i++) {
        // 填充yasuo[i]个dangqian
        for(int j = 0; j < yasuo[i]; j++) {
            dianzheng[hang][lie] = dangqian;
            lie++;
            if(lie == daxiao) { // 如果到行尾
                lie = 0; // 回到行首
                hang++; // 下一行
            }
        }
        dangqian = 1 - dangqian; // 切换0和1
    }
    
    // 输出点阵
    for(int i = 0; i < daxiao; i++) {
        for(int j = 0; j < daxiao; j++) {
            cout << dianzheng[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
