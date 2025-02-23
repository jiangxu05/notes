// 输入一串整数，以0结尾，逆置输出这一串整数，并且那个0不要了

//但是本题并不知道  数组大小， 只是从0到一百？？ 所以要用动态数组!!!

/*
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int a[101];
    for (int i = 1; i <= 100; i++) cin >> a [i];
    int n = sizeof(a) / sizeof(a[0]);

    reverse(a, a +n);
    for (int i = 1; i < 100; i++){
        cout << a[i] << " ";
    }
    return 0;
}
    */


    //不知数组大小就用动态数组
    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;
    
    int main() {
        vector<int> nums;  // 使用动态数组存储输入
        int num; //这个num够新鲜
    
        // 读取输入，直到遇到 0
        while (cin >> num && num != 0) { //还能这么写条件啊
            nums.push_back(num);  // 将输入的数存入动态数组，注意这个括号里面。。。
        }
    
        // 逆置数组
        reverse(nums.begin(), nums.end());
    
        // 输出逆置后的数组
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
    
        return 0;
    }
    //唉我还是太笨了；老老实实背完手敲吧