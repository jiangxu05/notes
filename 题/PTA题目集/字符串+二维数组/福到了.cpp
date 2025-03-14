//“福”字倒着贴，寓意“福到”。不论到底算不算民俗，本题且请你编写程序，把各种汉字倒过来输出。这里要处理的每个汉字是由一个 N × N 的网格组成的，网格中的元素或者为字符 @ 或者为空格。而倒过来的汉字所用的字符由裁判指定。
//输入在第一行中给出倒过来的汉字所用的字符、以及网格的规模 N （不超过100的正整数），其间以 1 个空格分隔；随后 N 行，每行给出 N 个字符，或者为 @ 或者为空格。
//输出倒置的网格，如样例所示。但是，如果这个字正过来倒过去是一样的，就先输出bu yong dao le，然后再用输入指定的字符将其输出。
//输入样例 1：
//$ 9
// @  @@@@@
//@@@  @@@ 
// @   @ @ 
//@@@  @@@ 
//@@@ @@@@@
//@@@ @ @ @
//@@@ @@@@@
// @  @ @ @
// @  @@@@@
//输出样例 1：
//$$$$$  $ 
//$ $ $  $ 
//$$$$$ $$$
//$ $ $ $$$
//$$$$$ $$$
// $$$  $$$
// $ $   $ 
// $$$  $$$
//$$$$$  $ 

#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
    char c;
    int N;
    cin >> c >> N;
    vector<vector<char>> grid(N, vector<char>(N));
    // 读入原始网格
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    
    // 检查是否对称
    bool symmetric = true;
    for(int i = 0; i < N && symmetric; i++) {
        for(int j = 0; j < N && symmetric; j++) {
            if(grid[i][j] != grid[N-1-i][N-1-j]) {
                symmetric = false;
            }
        }
    }
    
    // 如果对称,先输出提示语
    if(symmetric) {
        cout << "bu yong dao le" << endl;
    }
    
    // 输出倒置后的网格
    for(int i = N-1; i >= 0; i--) {
        for(int j = N-1; j >= 0; j--) {
            if(grid[i][j] == '@') {
                cout << c;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}  