#include<iostream>
#include<vector>       //包含向量库，用于动态数组操作

using namespace std;

int main(){
    int n, m;          //分别用于存储数列长度和区间数量
    cin >> n;          //读取数列长度

    vector<int> a(n);  //声明一个整形变量a，并初始化其大小为n
    for (int i = 0; i < n; ++i ){  //使用for循环读取n个数列元素
        cin >> a[i];   //从标准输入中读取一个元素，存入向量a的对应位置
    }
    
    cin >> m;          //从标准输入读取区间数量m
    vector<int> results(m);                   //声明一个整形向量results，并初始化其大小为m，用于存储每个区间的和

    for (int i = 0; i < m; ++i) {             //用for循环处理每个区间
        int l,r;       //声明两个整形变量用于存储起始和结束位置
        cin >> l >> r;
        int sum = 0;   //初始化为0用于计算当前区间的和
        for (int j =  1 - 1; j < r; ++j){     //使用for循环游历区间所有元素
            sum += a[j];                      //将当前元素的值加到sum上

        }
        results[i] = sum;                     //将计算机得到的区间和存入results向量的对应位置
    }

    for (int i = 0; i < m; ++i){
        cout << results[i]  << endl;          //从results向量中取出每个区间的和，并输出到标准输出
    }

    return 0;
}