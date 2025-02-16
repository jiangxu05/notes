#include <iostream>
#include <iomanip>                      // 用于设置输出精度
using namespace std;

int main() {
    double t;
    int n;
    cin >> t >> n;
    double perStudent = t / n;
    cout << fixed << setprecision(3);//无换行
    //最好写成一行,cout<<fixed<<setprecision(3)<<perStudent<<endl;
/*
    setprecision 是 iomanip 头文件中定义的一个函数，用于设置浮点数输出的精度，即小数点后的位数。
    fixed 是 iomanip 头文件中的一个操作符，它告诉输出流使用定点表示法来显示浮点数。
    在定点表示法中，数字总是以固定的形式显示，即小数点后有固定数量的数字，无论这个数字的大小如何。
*/
    cout << perStudent << endl;
    int totalCups = n * 2;
    cout << totalCups << endl;  
    return 0;
}
