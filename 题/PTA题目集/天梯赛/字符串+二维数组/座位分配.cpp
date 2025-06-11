//：假设某赛场有 N 所学校参赛，第 i 所学校有 M[i] 支队伍，每队 10 位参赛选手。令每校选手排成一列纵队，第 i+1 队的选手排在第 i 队选手之后。
//从第 1 所学校开始，各校的第 1 位队员顺次入座，然后是各校的第 2 位队员…… 以此类推。如果最后只剩下 1 所学校的队伍还没有分配座位，则需要安排他们的队员隔位就坐。
//本题就要求你编写程序，自动为各校生成队员的座位号，从 1 开始编号。

//输入格式：
//输入在一行中给出参赛的高校数 N （不超过100的正整数）；第二行给出 N 个不超过10的正整数，其中第 i 个数对应第 i 所高校的参赛队伍数，数字间以空格分隔。

//输出格式：
//从第 1 所高校的第 1 支队伍开始，顺次输出队员的座位号。每队占一行，座位号间以 1 个空格分隔，行首尾不得有多余空格。另外，每所高校的第一行按“#X”输出该校的编号X，从 1 开始。

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> M(N);
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }
    vector<vector<int>> seats(N, vector<int>(10));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M[i]; j++) {
            seats[i][j] = (i + 1) * 10 + j + 1;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << "#" << i + 1 << endl;
        for (int j = 0; j < M[i]; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}