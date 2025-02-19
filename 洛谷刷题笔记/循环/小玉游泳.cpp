#include<iostream>
using namespace std;
int main (){
    double s;
    int c = 0;
    cin >> s;
    for (double i =2 ; i < s/2.0 ; i*= 0.98){//改成i>0;
        s -= i;
        ++c;
    //if(s <= 0) return c;删掉

    }
    cout << c;
    return 0;
}
//纯自己做的，结果TEL，
//deepseek：你使用 i < s/2.0 作为循环条件，但 i 是通过 i *= 0.98 更新的，
//这意味着 i 会逐渐减小。如果 s 是一个较大的数，i 可能会变得非常小，导致循环次数过多，甚至可能陷入无限循环。

//你可以使用 s > 0 作为循环条件，这样当 s 变为负数或 0 时，循环会退出。

//徐改之后还是显示TEL；
//优化版本：
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double s;
    cin >> s;

    double a1 = 2.0;  // 首项
    double q = 0.98;  // 公比
    double sum = 0.0; // 前 c 项的和
    int c = 0;        // 步数

    while (sum < s) {
        sum += a1 * pow(q, c); // 累加每一步的距离
        c++;
    }

    cout << c << endl;
    return 0;
}
//等比数列