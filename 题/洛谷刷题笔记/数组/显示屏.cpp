//每个阿拉伯数字都是可以显示成 3×5 的点阵的（其中 X 表示亮点，. 表示暗点）。
//现在给出数字位数（不超过 100）和一串数字，要求输出这些数字在显示屏上的效果。数字的显示方式如同样例输出，注意每个数字之间都有一列间隔。
//输入格式
//第一行输入一个正整数 n，表示数字的位数。
//第二行输入一个长度为 n 的自然数。
//输出格式
//输出五行，表示显示屏上的数字。
//10
//0123456789
//输出
//XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
//X.X...X...X...X.X.X.X...X.....X.X.X.X.X
//X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
//x.X...X.X.....X...X...X.X.X...X.X.X...X
//XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 预定义每个数字的 3×5 点阵表示
const vector<vector<string>> digitPatterns = {
    {"XXX", "X.X", "X.X", "X.X", "XXX"}, // 0
    {"..X", "..X", "..X", "..X", "..X"}, // 1
    {"XXX", "..X", "XXX", "X..", "XXX"}, // 2
    {"XXX", "..X", "XXX", "..X", "XXX"}, // 3
    {"X.X", "X.X", "XXX", "..X", "..X"}, // 4
    {"XXX", "X..", "XXX", "..X", "XXX"}, // 5
    {"XXX", "X..", "XXX", "X.X", "XXX"}, // 6
    {"XXX", "..X", "..X", "..X", "..X"}, // 7
    {"XXX", "X.X", "XXX", "X.X", "XXX"}, // 8
    {"XXX", "X.X", "XXX", "..X", "XXX"}  // 9
};

int main() {
    int n;
    string number;
    cin >> n >> number;

    // 逐行输出
    for (int row = 0; row < 5; row++) {
        for (int i = 0; i < n; i++) {
            char ch = number[i];
            int digit = ch - '0'; // 将字符转换为数字
            cout << digitPatterns[digit][row]; // 输出当前行的点阵
            if (i < n - 1) { // 如果不是最后一个数字，输出间隔
                cout << ".";
            }
        }
        cout << endl; // 换行
    }

    return 0;
}