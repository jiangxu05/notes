//输入的第一行只有一个自然数 n，表示小明买的彩票张数；第二行存放了 7 个介于 1 和 33 之间的自然数，表示中奖号码；
//在随后的 n 行中每行都有 7 个介于 1 和 33 之间的自然数，分别表示小明所买的 n 张彩票。
//依次输出小明所买的彩票的中奖情况（中奖的张数），首先输出特等奖的中奖张数，然后依次输出一等奖至六等奖的中奖张数。
//特等奖七个号码全中，一等奖六个，六等奖1个，
//我的难点是如何读入n个数组 ？
#include <iostream>
#include <vector>
#include <algorithm> //包含find函数
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> win(7);
    for (int i = 0; i < 7; i++)
    {
        cin >> win[i];
    }
    //重点1:读取每张彩票的号码
    vector<vector<int>> buy(n, vector<int>(7));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> buy[i][j];
        }
    }

    // 统计中奖情况
    vector<int> ans(8, 0); // res[0]~res[7]，res[7]表示特等奖
    //中奖号码数量的范围是 0 到 7，因此需要 8 个位置来存储统计结果。
    //res(8, 0) 表示数组的大小为 8，索引范围是 0 到 7。
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < 7; j++) {
            // 使用 find 检查是否中奖
            //win.end() 不是 0，而是一个特殊的迭代器，用于表示查找失败。
            if (find(win.begin(), win.end(), buy[i][j]) != win.end()) {
                cnt++;
            }
        }
        ans[cnt]++; // 根据匹配数量统计中奖情况
    }

    // 输出结果（从特等奖到六等奖）
    for (int i = 7; i >= 1; i--) {
        cout << ans[i] << " ";
    
    return 0;
}

//如果找到，返回指向该元素的迭代器；否则返回 win.end()。
//通过判断 find 的返回值是否等于 win.end()，可以确定是否中奖