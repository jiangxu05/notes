//输入一个数，如果是奇数，乘3+1；偶数除2.循环后变成1，冰雹猜想
//要求存储每一次的变化，并且倒顺序输出，不知次数，动态数组，while循环
//我不知如何存入每次变化的数据

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v;

    while(n  !=  1){   //n不等于1时,但是n最后一个 都是1，所以看下一条注释

        if(n %2 == 0 ){
        v.push_back(n);
        n /= 2;
        }

        else{
        v.push_back(n);
        n = n*3 + 1;
        }
    }

    v.push_back(1);//

    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++){
        cout << v[i] <<" ";
    }
    //也可以这样：不用反转
    //for (int i = v.size() - 1; i >= 0; i--) {
    //    cout << v[i] << " ";
    //}

    return 0;

}