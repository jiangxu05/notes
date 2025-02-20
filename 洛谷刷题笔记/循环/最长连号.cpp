#include<iostream>

using namespace std;

//思路：

//输入n个整数，n个整数；

//最长连号：后 temp 等于前+1 b ；如果连号断了就要归一，连号长要临时存储 max;



int main (){

    int n ,  b , temp;
    int max = 1, ans = 0;
    cin>>n;

    cin >> b ;
    for (int i = 0; i < n ; i++){
        cin >> temp;
        if(temp == b + 1){
            ++max;
        }
        else max = 1;//这里错了不是0
        if (max > ans){
            ans = max;
        }
        b = temp;//别忘了更新前一位
    }
    cout << ans;
    return 0;
}
//ok也是AC了

