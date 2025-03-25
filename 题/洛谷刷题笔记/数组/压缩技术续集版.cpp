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
//正确
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string diyihang;
    cin >> diyihang;
    int n = diyihang.length();
    cout << n << " ";
    //存储点阵
    //vector<vector<string>> dianzheng(n,vector<string>(n));
    //这里使用了 vector<string> 来存储点阵，但实际上我们只需要存储单个字符，应该使用：
    vector<vector<char>> dianzheng(n,vector<char>(n));
    dianzheng[0] = vector<char>(diyihang.begin(),diyihang.end());
    for(int i = 1; i < n; i++){
        string hang;
        cin >> hang;
        dianzheng[i] = vector<char>(hang.begin(),hang.end());
    }
    //输出对应的个数
    int cnt = 0;
    char dangqian = '0';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dianzheng[i][j] == dangqian) cnt++;
            else{
                cout << cnt <<" ";
                cnt = 1;
                dangqian = dianzheng[i][j];
            }
        }
    }
    cout << cnt <<endl;
    return 0;
}
//我的错误
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string diyihang;
    cin >> diyihang;
    int n = diyihang.length();
    cout << n << " ";
    //存储点阵

    vector<vector<char>> dianzheng(n,vector<char>(n));
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> dianzheng[i][j];
        }
    }
    //输出对应的个数
    int cnt = 0;
    char dangqian = '0';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dianzheng[i][j] == dangqian) cnt++;
            else{
                cout << cnt <<" ";
                cnt = 1;
                dangqian = dianzheng[i][j];
            }
        }
    }
    cout << cnt <<endl;
    return 0;
}


//note
// 问题出在输入方式上：
// 正确代码：

// 先读取第一行字符串，然后根据这个字符串的长度确定点阵的大小。

// 接着，按行读取剩下的输入，每一行直接存到点阵中。

// 这种方式适合输入是按行提供的情况。

// 错误代码：

// 也是先读取第一行字符串，确定点阵大小。

// 但它接着逐个字符读取输入，假设输入是一个一个字符提供的。

// 这种方式适合输入是逐个字符提供的情况。

// 为什么会有差别？
// 如果你的输入是按行提供的（比如一行一行输入），错误代码会出错，因为它试图逐个字符读取，可能会读到换行符或其他乱七八糟的东西。

// 正确代码则是按行读取，完全匹配按行输入的情况。

