//对于我来说还是有点难
//P1009
#include <iostream>
#include <vector>
using namespace std;

// 高精度乘法：计算 a * b，结果存储在 a 中
void multiply(vector<int>& a, int b) {
    int carry = 0; // 进位
    for (int i = 0; i < a.size(); i++) {
        int product = a[i] * b + carry;
        a[i] = product % 10; // 当前位
        carry = product / 10; // 进位
    }
    while (carry) { // 处理剩余的进位
        a.push_back(carry % 10);
        carry /= 10;
    }
}

// 高精度加法：将 b 加到 a 中
void add(vector<int>& a, const vector<int>& b) {
    int carry = 0; // 进位
    for (int i = 0; i < b.size(); i++) {
        if (i < a.size()) {
            int sum = a[i] + b[i] + carry;
            a[i] = sum % 10; // 当前位
            carry = sum / 10; // 进位
        } else {
            int sum = b[i] + carry;
            a.push_back(sum % 10); // 当前位
            carry = sum / 10; // 进位
        }
    }
    while (carry) { // 处理剩余的进位
        a.push_back(carry % 10);
        carry /= 10;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> sum = {0}; // 存储最终结果 S，初始为 0
    vector<int> factorial = {1}; // 存储当前阶乘，初始为 1! = 1

    for (int i = 1; i <= n; i++) {
        multiply(factorial, i); // 计算 i!
        add(sum, factorial); // 将 i! 加到 S 中
    }

    // 输出结果
    for (int i = sum.size() - 1; i >= 0; i--) {
        cout << sum[i];
    }
    cout << endl;

    return 0;
}




//复杂度：
//假设你有一个任务：在一堆书里找到一本特定的书。
//方法 1：一本一本地找你从第一本开始，一本一本地检查，直到找到目标书。
//如果书的总数是 n那么最坏情况下你需要检查 n次。我们说这个方法的时间复杂度是 O(n)
//方法 2：书已经按字母顺序排好
//你可以用二分查找法：每次从中间开始找，排除一半的书。
//每次查找都能排除一半的书，所以最多需要 log2（n）。