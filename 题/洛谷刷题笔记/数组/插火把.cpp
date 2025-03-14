// 话说有一天 linyorson 在“我的世界”开了一个 n×n 的方阵，现在他有 m 个火把和 k 个萤石，分别放在 (x1,y1)∼(xm,ym) 和 (o1,p1)∼(ok,pk) 的位置，没有光并且没放东西的地方会生成怪物。请问在这个方阵中有几个点会生成怪物？

// P.S. 火把的照亮范围是：

//     |暗|暗| 光 |暗|暗|
//     |暗|光| 光 |光|暗|
//     |光|光|火把|光|光|
//     |暗|光| 光 |光|暗|
//     |暗|暗| 光 |暗|暗|
// 萤石：

//     |光|光| 光 |光|光|
//     |光|光| 光 |光|光|
//     |光|光|萤石|光|光|
//     |光|光| 光 |光|光|
//     |光|光| 光 |光|光|
// 输入格式
// 输入共 m+k+1 行。
// 第一行为 n,m,k。
// 第 2 到第 m+1 行分别是火把的位置 xi,yi。
// 第 m+2 到第 m+k+1 行分别是萤石的位置 oi,pi。

// 注：可能没有萤石，但一定有火把。
// 输出格式
// 有几个点会生出怪物。
// 输入输出样例
// 输入 
// 5 1 0
// 3 3
// 输出 
// 12
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int fangzhen_daxiao, huoba_shuliang, yingshi_shuliang;
    cin >> fangzhen_daxiao >> huoba_shuliang >> yingshi_shuliang;
    
    // 创建一个二维数组表示方阵,0表示暗的地方,1表示亮的地方
    vector<vector<int>> fangzhen(fangzhen_daxiao + 1, vector<int>(fangzhen_daxiao + 1, 0));
    
    // 处理火把
    for(int i = 0; i < huoba_shuliang; i++) {
        int x, y;
        cin >> x >> y;
        
        // 火把照亮范围
        // 中心十字
        for(int j = -2; j <= 2; j++) {
            if(x + j > 0 && x + j <= fangzhen_daxiao) fangzhen[x+j][y] = 1;
            if(y + j > 0 && y + j <= fangzhen_daxiao) fangzhen[x][y+j] = 1;
        }
        // 对角线部分
        for(int j = -1; j <= 1; j++) {
            for(int k = -1; k <= 1; k++) {
                if(x + j > 0 && x + j <= fangzhen_daxiao && 
                   y + k > 0 && y + k <= fangzhen_daxiao)
                    fangzhen[x+j][y+k] = 1;
            }
        }
    }
    
    // 处理萤石
    for(int i = 0; i < yingshi_shuliang; i++) {
        int x, y;
        cin >> x >> y;
        
        // 萤石照亮范围是5x5的正方形
        for(int j = -2; j <= 2; j++) {
            for(int k = -2; k <= 2; k++) {
                if(x + j > 0 && x + j <= fangzhen_daxiao && 
                   y + k > 0 && y + k <= fangzhen_daxiao)
                    fangzhen[x+j][y+k] = 1;
            }
        }
    }
    
    // 统计暗的地方(会生成怪物的地方)
    int guaiwu_shuliang = 0;
    for(int i = 1; i <= fangzhen_daxiao; i++) {
        for(int j = 1; j <= fangzhen_daxiao; j++) {
            if(fangzhen[i][j] == 0) guaiwu_shuliang++;
        }
    }
    
    cout << guaiwu_shuliang << endl;
    
    return 0;
}
/*
本题的难点和关键点:

1. 二维数组的使用
- 需要使用vector<vector<int>>创建二维数组来模拟方阵
- 数组大小要+1因为题目从1开始计数
- 初始化全为0表示未照亮

2. 边界检查很重要
- 在处理火把和萤石照亮范围时要检查坐标是否越界
- 使用 x+j > 0 && x+j <= fangzhen_daxiao 等条件判断

3. 火把照亮范围的处理
- 分为十字形和对角线两部分处理
- 十字形用两个单独的循环处理横竖方向
- 对角线部分用双重循环处理3x3范围

4. 萤石照亮范围的处理 
- 使用双重循环处理5x5的正方形范围
- 同样需要边界检查

5. 统计未照亮区域
- 遍历整个方阵
- 计数fangzhen[i][j] == 0的格子数量

6. 代码结构清晰
- 分别处理火把、萤石
- 最后统计暗区
*/
