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
/*
解题思路:
1. 输入第一个数N表示点阵大小
2. 后续数字交替表示连续的0和1的个数
3. 按从左到右、从上到下的顺序:
   - 用二维数组存储点阵
   - 遍历压缩码,根据当前数字填充相应个数的0或1
   - 每填满一行换到下一行
4. 最后按格式输出点阵
*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
/*
解题思路:
1. 输入第一个数N表示点阵大小
2. 后续数字交替表示连续的0和1的个数
3. 按从左到右、从上到下的顺序:
   - 用二维数组存储点阵
   - 遍历压缩码,根据当前数字填充相应个数的0或1
   - 每填满一行换到下一行
4. 最后按格式输出点阵
*/
//我的
    int n;
    cin >> n;
    vector<vector<int>> dianzhen(n,vector<int>(n,0));
    vector<int> shuzi;
    int m;
    while(cin >> m) shuzi.push_back(m);
    int hang = 0,lie = 0,now = 0;
    for(size_t i = 0;i < shuzi.size();i++){
        for(int j = 0; j < shuzi[i]; j++){
            dianzhen[hang][lie] = now;
            if(lie == n - 1){
                lie = 0;
                hang++;
            }
        }
        now = 1 - now;
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1;j++){
            cout << dianzhen[i][j];
        }
        cout << endl;
    }
    return 0 ;
    
}
//答案
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n; // 单独读取第一个数字 n

    vector<vector<int>> dianzhen(n, vector<int>(n, 0)); // 初始化点阵
    vector<int> shuzi;

    // 读取剩余的压缩码
    int m;
    while (cin >> m) {
        shuzi.push_back(m);
    }

    int hang = 0, lie = 0;
    int now = 0; // 初始填充 0

    // 填充点阵
    for (size_t i = 0; i < shuzi.size(); i++) { // 从第一个数字开始
        for (int j = 0; j < shuzi[i]; j++) {
            dianzhen[hang][lie] = now;
            lie++;
            if (lie == n) { // 换行
                lie = 0;
                hang++;
            }
        }
        now = 1 - now; // 切换 0 和 1
    }

    // 输出点阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dianzhen[i][j];
        }
        cout << endl;
    }

    return 0;
}