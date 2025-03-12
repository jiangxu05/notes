- 连续输出文本不用多个cout
```
int main()
{
    cout <<                                                             //连续输出的方法
    "                ********\n"
    "               ************\n"
    "               ####....#.\n"
    "             #..###.....##....\n"
    "            ###.......######              ###            ###\n"
    "                ...........               #...#          #...#\n"
    "               ##*#######                 #.#.#          #.#.#\n"
    "            ####*******######             #.#.#          #.#.#\n"
    "           ...#***.****.*###....          #...#          #...#\n"
    "           ....**********##.....           ###            ###\n"
    "           ....****    *****....\n"
    "             ####        ####\n"
    "           ######        ######\n"
    "############\n";     //注意最后这个分号
    return 0;
}
```

- 向上取整
```
#include <cmath>
...
    double v = 3.14*r*r*h;
    int n = ceil(20000.0/v);
```

- 浮点数精度
```
#include <iomanip> 
...
double t;
    int n;
    cin >> t >> n;
    double perStudent = t / n;
    cout << fixed << setprecision(3)perStudent<<endl;
```

- 反转字符串
```
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
```
- 字符大小写
```
char s;
    cin >> s;

    char m = s -('a'-'A'); //m大写，s小写，这么算就行。ASCII码大小写差32. //减法变字符，加法变数字；
    cout << m << endl;

```
```
#include <iostream>
#include <cctype>  // 包含 toupper 函数的头文件
using namespace std;

int main() {
    char c;
    cin >> c;  // 输入单个字符

    // 将字符转换为大写
    c = toupper(c);

    cout << c << endl;

    return 0;
}

```
### 根据书上看到的：
> 想要改变string对象中字符的值，必须把循环变量改成引用类型。
```
//不过 以下是改变字符串，而不是单个字符
#include<cctype>
string s("hello world");

for (auto &c : s) c = toupper(c);
```


- 判断闰年
```
#include <iostream>
using namespace std;

int main() {
    int year;
    cin >> year;

    // 判断闰年
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    cout << (isLeap ? "Yes" : "No") << endl;

    return 0;
}
```

- 最大公约数
```
//洛谷编译器识别不出来：手写gcd函数
int gcd(int a, int b) {
    while (b != 0) {  // 当 b 不为 0 时循环
        int t = b;    // 保存 b 的值
        b = a % b;    // 计算 a 除以 b 的余数，赋值给 b
        a = t;        // 将之前保存的 b 的值赋值给 a
    }
    return a;         // 当 b 为 0 时，a 就是最大公约数
}
```

- 三个值默认绑定 ABC是有顺序的并且从小到大绑定三个值，输出按照输入的ABC顺序输出值
```
#include<algorithm>
int arr[3];
    char A,B,C;
    cin>>arr[0]>>arr[1]>>arr[2];
    cin>>A>>B>>C;
    sort(arr,arr+3);
    cout<<arr[A-'A']<<" "<<arr[B-'A']<<" "<<arr[C-'A'];
```

- 必背题
```

//ISBN 号码///////ex //#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string isbn;
    cin >> isbn; // 读取输入的 ISBN 号码

    int sum = 0;
    // 计算前9位数字的加权和
    //for (int i = 0; i < 9; i++) 
    //   sum += (isbn[i] - '0') * (i + 1);//这里比较巧妙，减去‘0’就是转换成数字,记住了哈c
    //上面是错的，因为ISBN号码中包含分隔符-，但你在计算校验和时直接遍历前9个字符，错误地将这些分隔符当作数字处理。
    int count = 0;
    // 遍历整个字符串，提取前9个数字字符进行计算
    for (int i = 0; i < isbn.size() && count < 9; i++) {
        if (isdigit(isbn[i])) {
            count++;
            sum += (isbn[i] - '0') * count; // 正确累加加权和
        }
    }
    // 计算校验和
    int remainder = sum % 11;
    char checkDigit = (remainder == 10) ? 'X' : (char)(remainder + '0');//双目运算符

    // 检查校验码是否正确
    if (isbn.back()==checkDigit) 
        cout << "Right" << endl;
    else 
    {
        // 如果校验码不正确，输出正确的 ISBN 号码
        isbn.back() = checkDigit;
        cout << isbn << endl;
    }

    return 0;
}
/*在 C++ 中，字符实际上是以整数形式存储的，通常是 ASCII 值。字符 ‘0’ 的 ASCII 值是 48，字符 ‘1’ 的 ASCII 值是 49，以此类推。
所以，如果你有一个字符 ‘3’，执行 ‘3’ - ‘0’ 的操作将得到整数 3。单引号用于表示单个字符； 双引号用于表示字符串字面量*/
//'5' - '0' 相当于 53 - 48，结果是 5（整数）。
//整数 5 加上字符 '0' 的 ASCII 码（48），结果是 53，对应字符 '5'。
/*也是报错了：未正确处理分隔符：ISBN号码中包含分隔符-，但你在计算校验和时直接遍历前9个字符，错误地将这些分隔符当作数字处理。

校验码转换错误：将余数转换为字符时，错误地使用减法而非加法，导致校验码字符不正确。*/

```
### **找出给定范围 [a, b] 内的所有回文质数。回文质数是指既是质数，又是回文数的数。例如，11 是一个回文质数，因为它既是质数，又是回文数。**

- 根据数学性质优化范围（例如，偶数位数的回文数不可能是质数，除了 11）
- 埃氏筛法生成质数表;
book[i] 为 true 表示 i 是质数，false 表示 i 不是质数

```
#include<bits/stdc++.h>
using namespace std;

bool book[100000001];
```
> bool book[100000001];：定义一个布尔数组 book，用于标记质数。数组大小为 100000001，可以处理最大到 100000000 的数。

#### 埃氏筛法生成质数表
```
void prime(int b) {
    book[1] = false; // 1 不是质数
    int n = sqrt(b); // 只需要筛到 sqrt(b)
    for (int i = 2; i <= n; i++) {
        if (book[i]) { // 如果 i 是质数
            for (int j = 2; j <= b / i; j++) {
                book[i * j] = false; // 将 i 的倍数标记为非质数
            }
        }
    }
}
```
> memset(book, true, sizeof(book));
> memset 是一个 C/C++ 标准库函数，用于将一段内存区域设置为特定的值。这里 memset 将 book 数组的所有元素初始化为 true。  

> 注意sizeof(book) 返回数组 book 的总大小（以字节为单位）。这行代码的作用是假设所有数都是质数，后续再筛除非质数。


book[1] = false;：1 不是质数，手动标记为 false。


#### 判断回文数
```
bool isHWS(int num) {
    int temp = num, ans = 0;
    while (temp != 0) {
        ans = ans * 10 + temp % 10; // 将 temp 的最后一位加到 ans 中，实现  “数字反转”。
        temp /= 10; //去掉 temp 的最后一位。一定要记得这一步啊
    }
    if (ans == num) // 如果反转后的数字等于原数字
        return true;
    else
        return false;
}
```
> 注意数据类型是bool

##### 注释
通过 ans = ans * 10 + temp % 10 和 temp /= 10 实现数字反转。
> 例子：反转数字 123
- 第一次循环后``` ans=3 ; temp=12```
- 第二次循环```ans=ans=32 ;temp=1```就这样的往下。。。。。略
#### 主逻辑
```
int main() {
    int a, b;
    cin >> a >> b; // 输入范围 [a, b]
    if (b >= 10000000) // 如果 b 超过 10000000，则限制为 9999999
        b = 9999999;

    prime(b); // 生成质数表

    if (a > b) // 如果 a > b，直接结束
        return 0;

    if (a % 2 == 0) a++; // 如果 a 是偶数，则从 a+1 开始（因为偶数不可能是质数，除了 2）
    for (int i = a; i <= b; i += 2) { // 遍历奇数
        if (book[i] && isHWS(i)) // 如果 i 是质数且是回文数
            cout << i << endl; // 输出 i
    }
    return 0;
}
```

#### 优化方法防超时
- 偶数位数的回文数不可能是质数（除了 11）
```
```
- 跳过偶数
```
代码通过 if (a % 2 == 0) a++; 和 for (int i = a; i <= b; i += 2) 跳过所有偶数（除了 2），因为偶数不可能是质数。
```
## 阶乘之和
```
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
```

```

//输入质数 n； 求最大的因数，从 2开始遍历，小于根号n，之前学的性质；
#include<iostream>
#include<cmath>

using namespace std;

int main (){

    int n;
    cin >> n;

    for(int i = 2 ; i < sqrt(n) ; i++){ //注意2也是质数
        if (n % i == 0) cout<< n / i;
    }

    return 0;
}
```

```
//输入 n；打印矩形，直角三角形（直角在右边）
//两个循环 一个行数一个列数，0用iomanip
#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int n;
    cin >> n;

    int num = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << setw(2)<<setfill('0')<<num++;
        }
        cout <<endl;
    }
    
    cout <<endl;

    num = 1; //记得重赋值
    for (int i = 1; i <= n; i++){

        for(int j = 1; j <= n - i ; j++) cout << "  ";

        for(int k = 1; k <= i; k++) {
            cout<<setw(2)<<setfill('0')<<num++;
        }

        cout<<endl;
    }
    return 0;
}
```
## 排序
```
    vector<int>v1; //默认构造 无参构造
    for ( int i = 0; i < n; i++){
        
        cin >> num  ;
        v1.push_back(num);

    }
    sort(v1.begin(),v1.end());
```
## 筛选质数
```

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
```
## 最长连号
> 最长连号：后 temp 等于前+1 b ；如果连号断了就要归一，连号长要临时存储 max;
```

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
```
