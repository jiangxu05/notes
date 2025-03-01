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