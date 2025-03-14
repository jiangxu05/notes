//给出一个不大于 9 的正整数 n，输出 n×n 的蛇形方阵。
//从左上角填上 1 开始，顺时针方向依次填入数字，如同样例所示。注意每个数字有都会占用 3 个字符，前面使用空格补齐。
//输入格式
//输入一个正整数 n，含义如题所述。
//输出格式
//输出符合题目要求的蛇形矩阵。
#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> fangzhen(n, vector<int>(n));
    int num = 1;
    int left = 0, right = n-1, top = 0, bottom = n-1;
    //left：当前填充的左边界。
    //right：当前填充的右边界。
    //top：当前填充的上边界。
    //bottom：当前填充的下边界。
    while (left <= right && top <= bottom) {
        // 从左到右
        for (int i = left; i <= right; i++) {
            fangzhen[top][i] = num++;
        }
        top++;
        //从左边界 left 到右边界 right，填充上边（第 top 行）。
        //填充完后，上边界 top 向下移动一行。
        
        // 从上到下
        for (int i = top; i <= bottom; i++) {
            fangzhen[i][right] = num++;//先赋值，后自增。
        }
        right--;
        
        if (top <= bottom) {
            // 从右到左
            for (int i = right; i >= left; i--) {
                fangzhen[bottom][i] = num++;
            }
            bottom--;
        }
        
        if (left <= right) {
            // 从下到上
            for (int i = bottom; i >= top; i--) {
                fangzhen[i][left] = num++;//注意第一个【】是行，第二个【】是列。
            }
            left++;
        }
    }
    

    // 输出结果，每个数字占3个字符位置
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << fangzhen[i][j];
        }
        cout << endl;
    }
    return 0;
}