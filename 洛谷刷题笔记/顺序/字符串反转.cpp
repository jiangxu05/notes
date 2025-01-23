#include <iostream>
#include <string>        // 包含string头文件
#include <algorithm>     // 包含reverse算法的头文件，包含了各种通用的算法函数，排序、查找、复制等

using namespace std;

int main() {
    string a;            
    cin >> a;
    reverse(a.begin(), a.end()); // 反转字符串
    cout << a << endl;
    
    return 0;
}

//学习一下STL，标准模版库
//记一下万能头文件<bits/stdc++.h>

