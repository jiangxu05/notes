#include<iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e = c - a;
    int f = d - b;
    
    if(f < 0) {
        e--;
        f += 60;
    }
    
    e += f / 60;
    f = f % 60;                         // 用取余运算符计算分钟部分

    cout << e << " " << f << endl;  // 格式化输出，确保分钟部分是两位数
    return 0;
}