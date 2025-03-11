//给出两个整数 M 和 N
//第 1 行: 十个用空格分开的整数，分别表示数码 0…9 在序列中出现的次数。
//我的思路：遍历，while循环用模10取数字，数组记次数，输出时注意空格
#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin >> m >> n;
    int cishu[10] = {0};////数组未初始化：cishu 数组在使用前需要初始化为0，否则会导致未定义行为。

    for(int i =m ; i <= n; i++){
        int jieguo = i;
        
        while(jieguo > 0){ //循环条件错误：while(jieguo >= 0) 应该改为 while(jieguo > 0)，否则会导致无限循环。
            cishu[jieguo %  10]++;
            jieguo /=10;
        }
    }
    for(int i = 0; i < 10; i++){
        cout << cishu[i];
        if(i != 9){
            cout << " ";
        }
    }
    return 0;
}
//自己做的虽然出了一丢丢小错误。
