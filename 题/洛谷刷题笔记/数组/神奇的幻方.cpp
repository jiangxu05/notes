#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[45][45] = {}; // 幻方数组，初始化为0
    int k = 1; // 当前要填入的数字
    int x, y;  // 当前数字的位置

    while (k <= n * n) { // 循环直到填满所有数字
        if (k == 1) { // 第一个数字放在第一行的中间
            x = 1;
            y = n / 2 + 1;
        } else {
            // 根据幻方规则移动位置
            if (x == 1 && y != n) { // 如果在第一行且不在最后一列
                x = n; // 移动到最后一行
                y++;   // 列向右移动
            } else if (y == n && x != 1) { // 如果在最后一列且不在第一行
                x--;   // 行向上移动
                y = 1; // 移动到第一列
            } else if (x == 1 && y == n) { // 如果在第一行最后一列
                x++;   // 行向下移动
            } else {
                if (a[x-1][y+1] != 0) { // 如果右上角已经有数字
                    x++; // 行向下移动
                } else {
                    x--; // 行向上移动
                    y++; // 列向右移动
                }
            }
        }
        a[x][y] = k; // 填入数字
        k++; // 下一个数字
    }

    // 输出幻方
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
