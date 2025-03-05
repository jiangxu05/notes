//天天向上 
//读入努力值，绝对值小于1，可正可负数，0单独看，double类型，能力值基数为1.0输出365天后能力值变化百分比, 用c++
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    double x;
    cin >> x;
    if (x == 0){
        cout << "up:" <<"0.00%" << endl;
    }else{
        double y = pow(1 + x, 365);
        double z = (y - 1) * 100;
        if(z > 0 ){
            cout << fixed << setprecision(2) << "up:" << z << "%" << endl;
        }
    //下一个要求也要是正数
        else{
            cout << fixed << setprecision(2) << "down:" << -z << "%" << endl;
    }
    return 0;
}

//三天打鱼两天晒网，输入天n，输出第n天是打鱼还是晒网
#include <iostream>
using  namespace std;

int main(){
    int  n;
    cin >> n;
    //处理n小于等于5的情况
    if (n <= 5){
        if (n == 1 || n == 2 || n == 3){
            cout << "Fishing in day" << n << endl;
        }else{
            cout << "Dring in day" << n << endl;
        }
        return 0;
    }
    //处理n大于5的情况
    if (n % 5 == 1 || n % 5 == 2 || n % 5 == 3){
        cout << "Fishing in day" << n<< endl;
    }else{
        cout << "Dring in day"<<n<< endl;
    }
    return 0;
}



//输入一个字符表示等级，一个实数表示升数,题目已经给出每升的单价。
//要求计算一下费用，保留小数点两位。如果不在这A~B这二个等级中，则输出No available.
#include<iostream>
#include<iomanip>
using  namespace std;

int main(){
    char level;
    double num ;
    cin >> level >>num;
    if (level == 'A'){
        cout << fixed << setprecision(2) << num * 15.99 <<endl;
    }
    else if (level == 'B'){
        cout << fixed << setprecision(2) << num * 17.99 <<endl;\
    }
    else{
        cout << "No available." <<endl;
    }
    return 0;




}
//计算某年某月某日当天，是当年的第几天。直接输出年-月-日：整数。表示当日是第几天。年号占4位，不足4位时补前导零，月和日各占2位，不足2位也补前导零
//当年1月1日是第1天；2）每月按月大，月小，闰年等情况，各月天数有不同（31，30，28，29）；3）闰年按4年一闰，100年不闰，400年再闰计算。
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;


}


//判断三角形

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int  a,b,c;
    int arr[3];
    cin >> a >> b >> c;
    sort(arr,arr+3);
    if (arr[0] + arr[1] <= arr[2]) cout << "-1" <<endl;
    else {
        if (arr[0]*arr[0] + arr[1]*arr[1] == arr[2]*arr[2]) cout << "zhijiao" <<endl;
        else if (arr[0]*arr[0] + arr[1]*arr[1] > arr[2]*arr[2]) cout << "dunjiao；" <<endl;
        else cout << "ruijiao" <<endl;
    }
    return 0;

}//这题要记住int long long long double的范围;




//输入格式:表达式的格式为：s1 op s2，s1和s2是两个实数，op表示的是运算符+ - * /也可能是其他字符 
//输出格式:
//如果运算符合法，输出表达式的值；若运算符不合法或进行除法运算时除数是0，则输出Wrong input!。最后结果小数点后保留两位。 
//除数是0,用∣s2∣＜1e−10(即10的-10次方）判断 
#include<iostream>
#include<iomanip>
using namespace std;

int  main(){
    double s1,s2;
    char op;
    cin >> s1 >> op >> s2;
    if (op == '+') cout << fixed << setprecision(2) << s1 + s2 <<endl;
    else if (op == '-') cout << fixed << setprecision(2) << s1 - s2 <<endl;
    else if (op == '*') cout << fixed << setprecision(2) << s1 * s2 <<endl;
    else if (op == '/'){
        if (abs(s2) < 1e-10) cout << "Wrong input!" <<endl;
        else cout << fixed << setprecision(2) << s1 / s2 <<endl;
    }
    else cout << "Wrong input!" <<endl;
    return 0;
}


//输入泊车区域类别(整数：1，2，3)与泊车时长（实数）。一类区域以半小时为单位，例如：泊车时长2.3小时，应输入2.5；二类、三类区域以1小时为单位，例如：泊车时长2.3小时，应输入3 ）
//一类区域1小时内5元，超过1小时后，每半小时加收2元（不足半小时的，按半小时计），24小时最高收费50元；// 二类区域2小时内5元，超过2小时后，每小时加收2元（不足1小时的，按1小时计），
//24小时最高收费30元；// 三类区域3小时内5元，超过3小时后，每小时加收1元（不足1小时的，按1小时计），24小时最高收费20元。请根据泊车区域类别与泊车时长计算收费金额。
//也可以停放多天，费用累加
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int a;
    double b;
    cin >>  a >> b;
    if( a == 1 ){
        if (b <= 1) cout << fixed << setprecision(2) << 5 <<endl;
        else if (b <= 24) cout << fixed << setprecision(2) << 5 + (b - 1) / 0.5 * 2 <<endl;
        else if 
    return 0;
    }
}

//但是超过24小时就是另外一回事了。题目默认输入0.5的倍数
#include<iostream>
#include<iomanip>
#include<cmath> // 用于 ceil 函数
using namespace std;

int main() {
    int a;
    double b;
    cin >> a >> b;

    double fee = 0.0;
    // 计算完整的天数
    int days = static_cast<int>(b / 24);
    double remaining_hours = b - days * 24;

    // 根据区域类别计算费用
    if (a == 1) {
        // 一类区域
        fee += days * 50; // 每24小时最高收费50元
        if (remaining_hours <= 1) {
            fee += 5;
        } else if (remaining_hours <= 24) {
            fee += 5 + ceil((remaining_hours - 1) / 0.5) * 2;
            if (fee > days * 50 + 50) {
                fee = days * 50 + 50;
            }
        }
    } else if (a == 2) {
        // 二类区域
        fee += days * 30; // 每24小时最高收费30元
        if (remaining_hours <= 2) {
            fee += 5;
        } else if (remaining_hours <= 24) {
            fee += 5 + ceil((remaining_hours - 2) / 1) * 2;
            if (fee > days * 30 + 30) {
                fee = days * 30 + 30;
            }
        }
    } else if (a == 3) {
        // 三类区域
        fee += days * 20; // 每24小时最高收费20元
        if (remaining_hours <= 3) {
            fee += 5;
        } else if (remaining_hours <= 24) {
            fee += 5 + ceil((remaining_hours - 3) / 1) * 1;
            if (fee > days * 20 + 20) {
                fee = days * 20 + 20;
            }
        }
    }

    cout << fixed << setprecision(2) << fee << endl;

    return 0;
}

//第六题
#include<iostream>
#include<iomanip>
using namespace std;

// 判断是否为闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取某个月的天数
int getDaysInMonth(int year, int month) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int main() {
    int year, month, day;
    cin >> year >> month >> day;

    // 计算当年的第几天
    int dayOfYear = 0;
    for (int m = 1; m < month; ++m) {
        dayOfYear += getDaysInMonth(year, m);
    }
    dayOfYear += day;

    // 输出结果
    cout << setw(4) << setfill('0') << year << "-"
         << setw(2) << setfill('0') << month << "-"
         << setw(2) << setfill('0') << day << ":"
         << dayOfYear << endl;

    return 0;
}