//输入n个数字，输出每个数字前有几个数字比自己小


#include<iostream>

using namespace std;

int main(){
    int n,a[101],b[101];//只定义大小默认是0

    cin >> n;

    for (int  i = 1; i  <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++){
        for (int j = i; j >= 1; j--){ //固定i，让j递减就能比较了，
            if (a[i] > a [j]) b[i]++;
        }
    }
    for (int i = 1; i <= n; i++) cout << b[i]<< " ";//注意输出语句的位置，md还有这个空格别忘记了找半天发现格式错了
    return 0;
}