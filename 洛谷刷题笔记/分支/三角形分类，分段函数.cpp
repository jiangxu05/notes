/*如果三条线段不能组成一个三角形，输出Not triangle；
如果是直角三角形，输出Right triangle；
如果是锐角三角形，输出Acute triangle；
如果是钝角三角形，输出Obtuse triangle；
如果是等腰三角形，输出Isosceles triangle；
如果是等边三角形，输出Equilateral triangle。
*/

//先来默写一下冒泡排序：
/*
for(int i=0;i<3;i++){
    for(int j=0;j<3-i-1;i++){
        if(arr[i]>arr[i+1]){
            int temp=arr[i+1];
            arr[i+!]=arr[i];
            arr[i]=temp;
            }
    }
}
for(int i=0;i<3;i++){
    cout<<arr[i]
}*/
//我的理解在答案上稍微修改：
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    
    // 使用冒泡排序找到最大值
    for(int i = 0; i < 2; i++) { // 只需要两轮比较，因为总共有三个数
        if(a > b) swap(a, b); // 如果a大于b，交换它们
        if(b > c) swap(b, c); // 如果b大于c，交换它们，现在c是最大的
    }
    
    // 现在c是最大的数，下面是判断三角形的类型
    if(a + b <= c) {
        cout << "Not triangle";
        return 0;           //如果没有这个return 0，会继续执行下面的代码
    }
    if(pow(a, 2) + pow(b, 2) == pow(c, 2)) cout << "Right triangle" << endl;
    if(pow(a, 2) + pow(b, 2) > pow(c, 2)) cout << "Acute triangle" << endl;
    if(pow(a, 2) + pow(b, 2) < pow(c, 2)) cout << "Obtuse triangle" << endl;
    if(a == b || a == c || b == c) cout << "Isosceles triangle" << endl;
    if(a == b && b == c) cout << "Equilateral triangle" << endl;
    
    return 0;
}



//我的答案：
#include<iostream>
#include<iomanip>
using namespace std;

int main (){
    int n;
    cin >> n;
    double a;
    if(n<=150){
        a=0.4463*n;
 
        return 0;           //这里的return 0会导致往下的都不会执行
    }
    else if(n>=151&&n<=400){
        a=0.4463*150+(n-150)*0.4663;
       
    }
    else{
        a=0.4463*150+250*0.4663+(n-400)*0.5663;
    }
    cout<<fixed<<setprecision(1) ;//<<endl;一定要注意这里不能换行，否则会导致答案错误,最好写成一行
    cout<<a<<endl;
    return 0;
    
}