//一群人坐在一起，每人猜一个 100 以内的数，谁的数字最接近大家平均数的一半就赢。本题就要求你找出其中的赢家。
//输入格式：
//输入在第一行给出一个正整数N（≤10 
//4
// ）。随后 N 行，每行给出一个玩家的名字（由不超过8个英文字母组成的字符串）和其猜的正整数（≤ 100）。

//输出格式：
//在一行中顺序输出：大家平均数的一半（只输出整数部分）、赢家的名字，其间以空格分隔。题目保证赢家是唯一的。

//输入样例：
//7
//Bob 35
//Amy 28
//James 98
//Alice 11
//Jack 45
//Smith 33
//Chris 62
//输出样例：
//22 Amy
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    string name, winner;
    int num, sum = 0;
    int min_diff = 101;
    
    for(int i = 0; i < n; i++) {
        cin >> name >> num;
        sum += num;
        
        int target = sum/(2*(i+1));
        if(abs(num - target) < min_diff) {
            min_diff = abs(num - target);
            winner = name;
        }
    }
    
    cout << sum/(2*n) << " " << winner;
    return 0;
}


