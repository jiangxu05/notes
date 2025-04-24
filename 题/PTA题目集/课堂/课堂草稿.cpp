// 编程求正方形矩阵（n行n列）的左上到右下的一条对角线元素的和。

// 输入格式:
// 输入在第1行中给出n（1≤n≤100），在第2~n+1行中每行中给出n个整数，数字间以空格分隔。

// 输出格式:
// 左上到右下的对角线的和。

// 输入样例:
// 3
// 10 12 13
// 14 15 16 
// 17 18 19
// 输出样例:
// 44
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> shuju(n,vector<int>(n));
    for(int i=0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> shuju[i][j];
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += shuju[i][i];
    }
    cout << sum << endl;
    return 0;
}

// 编程求出一个m行n列矩阵中最大值，以及其所在的行号和列号（从0开始），输入的元素各不相同。

// 输入格式:
// 输入在第1行中给出m,n（1≤m≤20,（1≤n≤20），在第2~m+1行中每行中给出n个整数，数字间以空格分隔。

// 输出格式:
// 第一行最大值
// 第二行最大值的行号
// 第三行最大值的列号

// 输入样例:
// 3 5
// 2 7 9 8 1
// 5 4 3 19 12
// 17 22 11 4 6
// 输出样例:
// 22
// 2
// 1
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> shuju(m,vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) cin >> shuju[i][j];
    }
    int max = shuju[0][0];
    int x = 0,y = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(shuju[i][j] > max){
                max = shuju[i][j];
                x = i;
                y = j;
            }
        }
    }
    cout << max << endl;
    cout << x << endl;
    cout << y << endl;
    return 0;
}

// 编程实现将一个二维数组行和列元素互换，存到另一个二维数组中。

// 输入格式:
// 输入在第1行中给出m,n（1≤m≤20,（1≤n≤20），在第2~m+1行中每行中给出n个整数，数字间以空格分隔。

// 输出格式:
// 行列转置后的二维数组，每个数据占5列（题目保证每个数据不超过5列 ）。

// 输入样例:
// 3 5
// 2 7 9 8 1
// 5 4 3 9 2
// 7 2 1 4 6
// 输出样例:
//     2    5    7
//     7    4    2
//     9    3    1
//     8    9    4
//     1    2    6
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> shuju(m,vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) cin >> shuju[i][j];
    }
    int hang = 0,lie = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << setw(5) << shuju[hang][lie];
            hang++;
            if(hang == m){
                hang = 0;
                lie++;
                cout << endl;
            }
        }
    }
    return 0;
}

// 一个学习小组有6名同学，每人有3门必修课（数学、语文和英语），求每门课的平均分和每个人的平均分。

// 输入格式:
// 第1行输入6名同学的数学成绩。
// 第2行输入6名同学的语文成绩。
// 第3行输入6名同学的英语成绩。

// 输出格式:
// 在第1行分别输出数学、语文、英语3门课程的平均分，要求保留小数点后2位小数，数字之间用空格分隔。
// 在第2行分别输出6名同学的平均分，保留小数点后2位小数，数字之间用空格分隔。

// 输入样例:
// 在这里给出一组输入。例如：

// 85 93 84 85 95 86
// 79 95 95 80 100 98
// 80 91 93 75 97 90
// 输出样例:
// 在这里给出相应的输出。例如：

// 88.00 91.17 87.67 
// 81.33 93.00 90.67 80.00 97.33 91.33 
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int main(){
    vector<int> shuxue(6);
    vector<int> yinyu(6);
    vector<int> yuwen(6);
    for(int i = 0; i < 6; i++) cin >> shuxue[i];
    for(int i = 0; i < 6; i++) cin >> yinyu[i];
    for(int i = 0; i < 6; i++) cin >> yuwen[i];
    double shuxuecj = 0,yinyucj = 0,yuwencj = 0;
    for(int i = 0; i < 6; i++){
        shuxuecj += shuxue[i];
        yinyucj += yinyu[i];
        yuwencj += yuwen[i];
    }
    shuxuecj /= 6;
    yinyucj /= 6;
    yuwencj /= 6;
    cout << fixed << setprecision(2) <<  shuxuecj << " " << yinyucj << " " << yuwencj << endl;
    for(int i = 0; i < 6; i++){
        double pj = (shuxue[i] + yinyu[i] + yuwen[i]) / 3;
        cout << fixed << setprecision(2) << pj << " ";
    }
    return 0;
}

// 输入一个 n 行 m 列的整数矩阵，再输入 q 个询问，每个询问包含四个整数 x1,y1,x2,y2，表示一个子矩阵的左上角坐标和右下角坐标。

// 对于每个询问输出子矩阵中所有数的和。

// 输入格式
// 第一行包含三个整数 n，m，q。

// 接下来 n 行，每行包含 m 个整数，表示整数矩阵。

// 接下来 q 行，每行包含四个整数 x1,y1,x2,y2，表示一组询问。

// 输出格式
// 共 q 行，每行输出一个询问的结果。

// 数据范围
// 1≤n,m≤100,
// 1≤q≤200,
// 1≤x1≤x2≤n,
// 1≤y1≤y2≤m,

// 输入样例:
// 3 4 3
// 1 7 2 4
// 3 6 2 8
// 2 1 2 3

// 1 1 2 2
// 2 1 3 4
// 1 3 3 4
// 输出样例:
// 17
// 27
// 21
#include<iostream>
#include<vector>
using namespace std;

int qiuhe(vector<vector<int>> shuju,int x1,int y1,int x2,int y2){
    int sum = 0;
    for(int i = x1; i <= x2; i++){
        for(int j = y1; j <= y2; j++) sum += shuju[i][j];
    }
    return sum;
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> shuju(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> shuju[i][j];
    }
    for(int i = 0; i < q; i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--,y1--,x2--,y2--;//将坐标转换为0-based,不然显示段错误
        cout << qiuhe(shuju,x1,y1,x2,y2) << endl;
    }
    return 0;
}

// 中国福利彩票中心推出双色球福利彩票多年，一注单式双色球号码由6个不同的红色球号码和1个蓝色球号码组成，其中，红色号码是1-33之间整数，蓝色号码是1-16之间的整数。
//彩民购买的彩票号码与开奖公布的彩票号码分别满足相应条件可兑换相应的奖励。具体兑奖规则如下：
//    一位彩民购买了n注单式双色球彩票，请根据开奖公布的号码判断该彩民中奖情况。

// 输入格式:
// 第1行,输入一个整数n,表示彩民买了n组彩票.0<=n<=100。
// 第2行是开奖公布的号码，第1个到第6个是已按升序排列的红色中奖号码，第7个是蓝色中奖号码；
// 第3行到n+2行是彩民买的n组单式彩票,每行第1个到第6个是已按升序排列的红色中奖号码，第7个是蓝色号码。

// 输出格式:
// 按输入顺序输出已中奖的彩票号码及中奖等级,每组中奖号码占1行，中奖号码与中奖等级间有1个空格；若所有的彩票均未中奖，最后输出 “Not winning”。

// 输入样例1:
// 6
// 02  06  10  24  25  33  09
// 03  09  10  19  20  21  06
// 01  06  09  15  24  30  02
// 02  03  06  24  25  33  05
// 20  21  24  27  28  30  02
// 10  11  12  16  17  20  16
// 02  06  10  24  25  33  09
// 输出样例1:
// 02 03 06 24 25 33 05 四等奖
// 02 06 10 24 25 33 09 一等奖
// 输入样例2:
// 4
// 02  06  10  24  25  33  09
// 03  09  10  19  20  21  06
// 01  06  09  15  24  30  02
// 20  21  24  27  28  30  02
// 10  11  12  16  17  20  16
// 输出样例2:
// Not winning
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt = 0;
    vector<int> win(7);
    for(int i = 0; i < 7; i++) cin >> win[i];
    vector<vector<int>> buy(n,vector<int>(7));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 7; j++) cin >> buy[i][j];
    }
    for(int i = 0; i < n; i++){
        int red = 0,blue = 0;
        for(int j = 0; j < 6; j++){
            if(find(win.begin(),win.begin()+6,buy[i][j]) != win.begin()+6) red++;
        }
        if(buy[i][6] == win[6]) blue = 1;
        if(red == 6 && blue == 1) cout << setw(2) << setfill('0') << buy[i][0] << " " << setw(2) << setfill('0') << buy[i][1] << " " << setw(2) << setfill('0') << buy[i][2] << " " << setw(2) << setfill('0') << buy[i][3] << " " << setw(2) << setfill('0') << buy[i][4] << " " << setw(2) << setfill('0') << buy[i][5] << " " << setw(2) << setfill('0') << buy[i][6] << " 一等奖" << endl;
        else if(red == 6 && blue == 0) cout << setw(2) << setfill('0') << buy[i][0] << " " << setw(2) << setfill('0') << buy[i][1] << " " << setw(2) << setfill('0') << buy[i][2] << " " << setw(2) << setfill('0') << buy[i][3] << " " << setw(2) << setfill('0') << buy[i][4] << " " << setw(2) << setfill('0') << buy[i][5] << " " << setw(2) << setfill('0') << buy[i][6] << " 二等奖" << endl;
        else if(red == 5 && blue == 1) cout << setw(2) << setfill('0') << buy[i][0] << " " << setw(2) << setfill('0') << buy[i][1] << " " << setw(2) << setfill('0') << buy[i][2] << " " << setw(2) << setfill('0') << buy[i][3] << " " << setw(2) << setfill('0') << buy[i][4] << " " << setw(2) << setfill('0') << buy[i][5] << " " << setw(2) << setfill('0') << buy[i][6] << " 三等奖" << endl;
        else if((red == 5 && blue == 0 )|| (red == 4 && blue == 1)) cout << setw(2) << setfill('0') << buy[i][0] << " " << setw(2) << setfill('0') << buy[i][1] << " " << setw(2) << setfill('0') << buy[i][2] << " " << setw(2) << setfill('0') << buy[i][3] << " " << setw(2) << setfill('0') << buy[i][4] << " " << setw(2) << setfill('0') << buy[i][5] << " " << setw(2) << setfill('0') << buy[i][6] << " 四等奖" << endl;
        else if((red == 4 && blue == 0)|| (red == 3 && blue == 1)) cout << setw(2) << setfill('0') << buy[i][0] << " " << setw(2) << setfill('0') << buy[i][1] << " " << setw(2) << setfill('0') << buy[i][2] << " " << setw(2) << setfill('0') << buy[i][3] << " " << setw(2) << setfill('0') << buy[i][4] << " " << setw(2) << setfill('0') << buy[i][5] << " " << setw(2) << setfill('0') << buy[i][6] << " 五等奖" << endl;
        else if((red == 2 && blue == 1)||(red == 1 && blue == 1)||(red == 0 && blue == 1))cout << setw(2) << setfill('0') << buy[i][0] << " " << setw(2) << setfill('0') << buy[i][1] << " " << setw(2) << setfill('0') << buy[i][2] << " " << setw(2) << setfill('0') << buy[i][3] << " " << setw(2) << setfill('0') << buy[i][4] << " " << setw(2) << setfill('0') << buy[i][5] << " " << setw(2) << setfill('0') << buy[i][6] << " 六等奖" << endl;
        else cnt++;
    }
    if(cnt == n) cout << "Not winning" << endl;
    return 0;
}



// 编码实现n阶（n为正奇数）幻方。

// 本题检测算法（n为奇数时）：

// 1）将1放在第一行中间一列；

// 2）从2开始直到n×n止各数依次按下列规则存放：按45°方向行走，如向右上；每一个数存放的行比前一个数的行数减1，列数加1。

// 3）如果行列范围超出矩阵范围，则回绕，例如1在第1行，则2应放在最后一行，列数同样加1。

// 4）如果按上面规则确定的位置上已有数，则把下一个数放在上一个数的下面。

// 输入格式:
// 输入阶数n（n为小于等于15的正奇数）。

// 输出格式:
// n阶幻方，每个数据占5列

// 输入样例:
// 3
// 输出样例:
//     8    1    6
//     3    5    7
//     4    9    2
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> magicSquare(n, vector<int>(n, 0)); // 使用vector初始化n×n的幻方，初始化为0
    int k = 1; // 当前要填入的数字
    int x, y;  // 当前数字的位置

    while (k <= n * n) { // 循环直到填满所有数字
        if (k == 1) { // 第一个数字放在第一行的中间
            x = 0;
            y = n / 2;
        } 
        else {
            // 根据幻方规则移动位置
            if (x == 0 && y != n - 1) { // 如果在第一行且不在最后一列
                x = n - 1; // 移动到最后一行
                y++;       // 列向右移动
            } 
            else if (y == n - 1 && x != 0) { // 如果在最后一列且不在第一行//重点
                x--;       // 行向上移动
                y = 0;     // 移动到第一列
            } 
            else if (x == 0 && y == n - 1) { // 如果在第一行最后一列
                x++;       // 行向下移动
            } 
            else {
                if (magicSquare[x - 1][y + 1] != 0) { // 如果右上角已经有数字
                    x++; // 行向下移动
                } 
                else {
                    x--; // 行向上移动
                    y++; // 列向右移动
                }
            }
        }
        magicSquare[x][y] = k; // 填入数字
        k++; // 下一个数字
    }

    // 输出幻方
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magicSquare[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
