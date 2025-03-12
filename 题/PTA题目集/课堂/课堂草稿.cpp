//365天，每天UP：1‰，一年之后就可以成长为原来的1.44倍；相反，每天DOWN1‰，一年后就只剩下原来的0.69。
//如果每天UP：1%，一年后就是原来的37.78倍；同样，每天DOWN：1%，就只剩原来的0.026。
//本题考虑工作日和周末的情况，即工作日每天UP：1%，而周末每天DOWN：1%，n天后情况又如何呢？ 假定开始UP的起始日是周一，且初始能力值为100。
//输入格式:一个正整数n
//输出格式:
//一个浮点数，代表n天之后的能力值
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double ability = 100.0; // 初始能力值
    int n;
    cin >> n; // 输入天数

    for (int day = 1; day <= n; day++) {
        // 判断当前是工作日还是周末
        if (day % 7 >= 1 && day % 7 <= 5) {
            // 工作日：能力值增加 1%
            ability *= 1.01;
        } else {
            // 周末：能力值减少 1%
            ability *= 0.99;
        }
    }

    // 输出结果，保留两位小数
    cout << ability;
    return 0;//
}

//编程求如下序列前n项的和。
//sum = 1/2 + 3/4 + 5/6 + 7/8 + 9/10 + ……。
#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    double sum = 0.00;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        sum += (2 * i - 1) / static_cast<double>(2 * i); // 将分母转换为 double//sum += (2 * i - 1) / (2 * i); // 计算每一项的值并累加到sum中
    }
    cout << fixed << setprecision(2) << sum << endl; // 输出结果，保留两位小数
    return 0;
}


//找出所有满足要求的四位数（由小到大）。要求一个四位数恰好等于它的前两位加后两位和的平方. 比如：3025=(30+25)*(30+25)
#include<iostream>
using namespace std;

int main(){
    for(int i = 1001; i <= 9999; i++){
        int qianliangwei = i / 100, houliangwei = i % 100;
        if ((qianliangwei + houliangwei)*(qianliangwei + houliangwei)  == i ) cout << i << endl;
    }
    return 0;
}

//若干学生的成绩，统计并输出最高成绩和最低成绩，当输入负数时循环结束。。在一行中输入若干个用空格间隔的整数（不要超过15个数），最后输入负数结束输入，数据之间只能用1个空格间隔。
//在一行中按照“max=最高分,min=最低分”的格式输出结果，最高分和最低分均原样输出，没有列宽控制。
#include <iostream>
#include <vector>
#include <algorithm> // 用于 sort 函数
using namespace std;

int main() {
    vector<int> chengji; // 用于存储成绩的vector
    int n;

    // 输入成绩，直到输入负数
    while (cin >> n) {
        if (n < 0) break; // 输入负数时结束循环
        chengji.push_back(n); // 将非负成绩存入向量
    }

    // 对成绩进行排序
    sort(chengji.begin(), chengji.end());

    //begin 和 end 通常用于遍历容器。迭代器
    //end 返回的迭代器指向的是容器的“尾后位置”，不能直接解引用。

    // 输出最高分和最低分
    cout << "max=" << chengji.back() << ",min=" << chengji.front() << endl;

    //front 返回容器中第一个元素的引用。
    //back 返回容器中最后一个元素的引用。

    return 0;
}


//for(int x = n + 1; ;x++) 

//计算位数cnt，计算总和sum；

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >>n;
    int sum = 0,weishu = 0;
    while(n != 0){
        sum += n%10;
        n /= 10;
        weishu++;
    }
    cout <<weishu <<" "<<sum << endl;
    return 0;
}

//输出大于n，能被k整除的最小整数x；
//超时代码只有8分
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (k == 0) return 0;

    for (int x = n + 1; ; x++) {
        if (x % k == 0) {
            cout << x << endl;
            break;
        }
    }

    return 0;
}
//数学方法：
#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin >>n >> k;
    cout<< n / k * k + k;
    return 0;
}
