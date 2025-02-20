/*先让deepseek来帮帮忙：
质数（Prime Number）是指大于 1 的自然数，且只能被 1 和它本身整除的数。换句话说，质数没有其他因数。
试除法：判断一个数 n 是否为质数，只需要检查从 2 到 根号n的所有整数是否能整除 。如果 n 不是质数，它至少有一个因数小于或等于 n。*/
#include <iostream>
#include <vector>
using namespace std;

void findPrimes(int n) {
    // 初始化一个布尔数组，表示每个数是否为质数
    vector<bool> isPrime(n + 1, true);  // 默认所有数都是质数
    isPrime[0] = isPrime[1] = false;    // 0 和 1 不是质数

    // 从 2 开始遍历到 sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {  // 如果 i 是质数
            // 将 i 的所有倍数标记为非质数
            for (int j = i * i; j <= n; j += i) {//从 i的平方开始标记，因为比i的平方小的已经被更小的质数标记过了；
                isPrime[j] = false;
            }
        }
    }

    // 输出所有质数
    cout << "质数列表: ";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) cout << i << endl;
    }
    cout << endl;
}

int main() {
    int num;
    cout << "请输入一个整数: ";
    cin >> num;

    findPrimes(num);  // 调用函数找出所有质数

    return 0;
}





