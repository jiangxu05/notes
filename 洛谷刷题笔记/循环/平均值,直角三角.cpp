#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int sum1 = 0, sum2 = 0, count1 = 0, count2 = 0;//这里我之前没有初始化，注意了哈

    for (int i = 1; i <= n; ++i) { // 从1遍历到n
        if (i % k == 0) {
            sum1 += i;
            count1++;
        } else {
            sum2 += i;
            count2++;
        }
    }

    // 处理分母为零的情况，//这种方法之前没见过；
    double ans1 = count1 ? static_cast<double>(sum1) / count1 : 0.0;//意思是如果count1不为0，就计算sum1/count1，否则为0；
    double ans2 = count2 ? static_cast<double>(sum2) / count2 : 0.0;//三目
    //在这里，它的作用是将整数（int）转换为浮点数（double），以便进行浮点数除法，避免整数除法丢失小数部分的问题。

    cout << fixed << setprecision(1) << ans1 << " " << ans2;
    return 0;
}



int main1()
{
    int n;
    cin >> n;

    int num = 1; //想清楚这里为什么是1哈

    for (int i = 0; i < n; i++) //控制行数
    {
        for (int j = 0; j < n-i; j++)//注意这里的循环条件是我没想到的，由样例可以发现规律哈,模拟一下就发现是-i，脑海里循环
        {
            if (num < 10) //别写成了<9哈，检查了半天，c
            {
                cout << 0 << num;
            } else {
                cout << num;
            }
            num++;
        }
        cout << endl;
    }
    return 0;
}
//火速手敲