//函数题
//1题面：水仙花数是指一个三位正整数，它的每个位上的数字的3 次幂之和等于它本身。例如：153=1，则153 是水仙花数。 本题要求编写一个函数判断给定整数是否是水仙花数。
#include<cmath>
bool narcissistic( int number ){
    if(number > 99 && number <1000){
        if(number == pow((number/100),3) + pow(number/10%10,3) + pow (number%10,3))
        return true;
        else return false;
    }
    else return false;
        }

//2:编写getDis 函数，计算平面坐标系内两点的距离。
double getDis(double x1, double y1,double x2,double y2){
    double ans = 0.0;
    return pow(pow((y2-y1),2)+pow((x2 - x1),2),0.5);
}
//3:月用电量50 千瓦时（含50 千瓦时）以内的，电价为0.53 元/千瓦时；超过50 千瓦时的，超出部分的用电量，电价上调0.05 元/千瓦时。若电量小于等于0，输出0。请编写程序在主函数中输入用电量，然后调用函数计算电费并在主函数中输出。

double getCost(double x){
    if(x <= 0) return 0;
    else{
        if(x <= 50.0) return 0.53*x;
        else return 0.53*50 + 0.58*(x - 50);
    }
}
//4求pi值
double pai() {
    double ans = 1.0;
    double temp = 1.0;
    double n = 1.0; 

    while (temp >= 1e-8) {
        temp *= n / (2 * n + 1); 
        ans += temp;
        n += 1.0; 
    }

    return 2 * ans; 
}

//5gcd函数
int gcd(int m,int n){
    while(n != 0){
        int temp;
        temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}

//编程题
//1幸运数
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    int cnt4 = 0, cnt7 = 0;

    if (n >= 4) {
        long long temp = n;
        while (temp % 4 == 0) {
            cnt4++;
            temp /= 4;
        }
    }

    if (n >= 7) {
        long long temp = n;
        while (temp % 7 == 0) {
            cnt7++;
            temp /= 7;
        }
    }

    cout << cnt4 << " " << cnt7 << endl;
    return 0;
}
//2第一行一个整数n，表示星星的数量。
//接下来共n行，每行2个正整数(a,b)，表示该星星到X轴距离为b，到Y轴距离为a，这些星星只会位于X轴的上方，Y轴的右方。
//输入数据保证存在一个合法的正方形（面积非零）去覆盖这些星星
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n ;
    cin >> n;
    vector<int> xzuobiao(n,0);
    vector<int> yzuobiao(n,0);

    for(int i = 0; i < n; i++){
        cin >> xzuobiao[i] >> yzuobiao[i];
    }

    sort(xzuobiao.begin(),xzuobiao.end());
    sort(yzuobiao.begin(),yzuobiao.end());

    int xchazhi = xzuobiao.back() - xzuobiao.front();
    int ychazhi = yzuobiao.back() - yzuobiao.front();
    long long ans = pow(max(xchazhi,ychazhi),2);
    cout << ans << endl;
    return 0;
}

//3输出给定年份区间之内的所有闰年；输出[begin, end]区间内所有的闰年。
//每个年份占6列（右对齐），每5个闰年换一行。
#include<bits/stdc++.h>
using namespace std;
bool runnian(int num){
    if ((num % 4 == 0 && num % 100 != 0) || num % 400 == 0) return true;
    else return false;
}
int main(){
    int m,n;
    cin >> m >> n;
        int cnt = 0;
    for(int i = m; i <= n; i++){

        if(runnian(i)){
            cout <<setw(6)<<i;
            cnt++;
            if(cnt == 5){
                cout << endl;
                cnt = 0;
            }
        }
    }
    return 0;
}
//4信有一队兵，他想知道有多少人，便让士兵排队报数。
// 按3人成行排列，多2人；
// 按5人成行排列，多3人；
// 按7人成行排列，多2人；
// 请问韩信至少有多少兵？
// 请输入两个正整数A和B（A<B），输出A和B间第一个满足条件的数，如果不存在输出no。
// 输入格式:
// 输入两个正整数：A B
// 输出格式:
// 如果存在满足条件的数C输出：C
// 否则输出：no

#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int cnt = 0;
    for(int i = a; i <= b; i++){
        if((i%3 == 2) && (i % 5 == 3)&& (i%7==2)) {
            cout << i;
            cnt++;
        }
    }
    if(cnt == 0) cout <<"no"<<endl;
    return 0;
}