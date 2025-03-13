//所有满足 x 1 ≤i≤x 2 ，y 1 ≤j≤y 2 ，z 1≤k≤z 2的小方块 (i,j,k) 的点都会被激光蒸发。例如有一个 4×4×4 的大方块，其体积为 64；给出参数 (1,1,1),(2,2,2) 时，中间的 8 块小方块就会被蒸发，剩下 56 个小方块。现在想知道经过所有切割操作后，剩下的工艺品还剩下多少格小方块的体积？
//输入格式
//第一行三个正整数 w,x,h。
//第二行一个正整数 q。
//接下来 q 行，每行六个整数 (x1,y1,z1),(x2,y2,z2)。
//输出格式
//输出一个整数表示答案。
//输入样例
//4 4 4
//1
//1 1 1 2 2 2
//输出：56;
//我的难点就是不知道切割了多少个小块？三维数组？
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a,b,c,q;
    cin >> a >> b >> c >> q;

    vector<vector<int>> qiegecanshu(q,vector<int>(6));

    for(int i = 0; i < q; i++){
        for (int j = 0; j < 6; j++){
            cin >> qiegecanshu[i][j];
        }
    }

}



//正解：
//具体来说，可以使用一个 bool 类型的三维数组，其中 true 表示该小方块未被蒸发，false 表示该小方块已被蒸发。#include<iostream>
#include<vector>
using namespace std;

int main() {
    int w, x, h, q;
    cin >> w >> x >> h >> q;

    // 初始化三维数组，表示每个小方块是否被切割过
    vector<vector<vector<bool>>> isCut(w + 1, vector<vector<bool>>(x + 1, vector<bool>(h + 1, false)));

    // 读取切割操作
    for (int i = 0; i < q; i++) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        // 遍历切割范围内的所有小方块，标记为被切割
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                for (int k = z1; k <= z2; k++) {
                    isCut[i][j][k] = true; // 标记为被切割
                }
            }
        }
    }

    // 统计被切割的小方块数量
    int cutCount = 0;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= h; k++) {//注意从1开始啊；；；
                if (isCut[i][j][k]) {
                    cutCount++; // 如果被切割过，增加计数
                }
            }
        }
    }

    // 计算剩余的小方块数量
    int total = w * x * h; // 总体积
    int remaining = total - cutCount; // 剩余体积

    // 输出结果
    cout << remaining << endl;

    return 0;
}

//一维数组：

//像一排盒子，每个盒子有一个编号（索引）。

//例如：vector<bool> arr(10, false) 表示一排 10 个盒子，初始状态为 false。

//二维数组：

//像一个表格，有行和列。

//例如：vector<vector<bool>> arr(5, vector<bool>(10, false)) 表示一个 5 行 10 列的表格，每个格子初始状态为 false。

//三维数组：

//像一个立方体，有层、行和列。

//例如：vector<vector<vector<bool>>> arr(3, vector<vector<bool>>(4, vector<bool>(5, false))) 表示一个 3 层、每层 4 行 5 列的立方体，每个小方块初始状态为 false。