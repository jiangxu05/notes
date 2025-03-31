- string 则是一个简单的类，使用简单，在 OI 竞赛中被广泛使用。并且相较于其他 STL 容器，string 的常数可以算是非常优秀的，基本与字符数组不相上下。
- string 能动态分配空间，这使得我们可以直接使用 std::cin 来输入，但其速度则同样较慢。这一点也同样让我们不必为内存而烦恼。

## 获取长度
cout << "s 的长度为 " << s.size() << endl;
cout << "s 的长度为 " << s.length() << endl;
cout << "s 的长度为 " << strlen(s.c_str()) << endl;

## 找某字符（串）第一次出现的位置
string s = "OI Wiki", t = "OI", u = "i";
int pos = 5;
cout << "字符 I 在 s 的 " << s.find('I') << " 位置第一次出现" << endl;
cout << "字符 a 在 s 的 " << s.find('a') << " 位置第一次出现" << endl;
cout << "字符 a 在 s 的 " << static_cast<int>(s.find('a')) << " 位置第一次出现" << endl;
cout << "字符串 t 在 s 的 " << s.find(t) << " 位置第一次出现" << endl;
cout << "在 s 中自 pos 位置起字符串 u 第一次出现在 " << s.find(u, pos) << " 位置" << endl;
- 输出
```
字符 I 在 s 的 1 位置第一次出现
字符 a 在 s 的 18446744073709551615 位置第一次出现 // 即为 size_t(-1)，具体数值与平台有关。
字符 a 在 s 的 -1 位置第一次出现 // 强制转换为 int 类型则正常输出 -1
字符串 t 在 s 的 0 位置第一次出现
在 s 中自 pos 位置起字符串 u 第一次出现在 6 位置
```

## 截取子串
substr(pos, len) 函数的参数返回从 pos 位置开始截取最多 len 个字符组成的字符串（如果从 pos 开始的后缀长度不足 len 则截取这个后缀）。
string s = "OI Wiki", t = "OI";
cout << "从字符串 s 的第四位开始的最多三个字符构成的子串是 " << s.substr(3, 3) << endl;
cout << "从字符串 t 的第二位开始的最多三个字符构成的子串是 " << t.substr(1, 3) << endl;
- 输出
```
从字符串 s 的第四位开始的最多三个字符构成的子串是 Wik
从字符串 t 的第二位开始的最多三个字符构成的子串是 I
```

## 插入/删除字符（串）
string s = "OI Wiki", t = " Wiki";
char u = '!';
s.erase(2);
cout << "从字符串 s 的第三位开始删去所有字符后得到的字符串是 " << s << endl;
s.insert(2, t);
cout << "在字符串 s 的第三位处插入字符串 t 后得到的字符串是 " << s << endl;
s.insert(7, 3, u);
cout << "在字符串 s 的第八位处连续插入 3 次字符串 u 后得到的字符串是 " << s << endl;


## 替换字符（串）
string s = "OI Wiki";
s.replace(2, 5, "");
cout << "将字符串 s 的第 3~7 位替换为空串后得到的字符串是 " << s << endl;
s.replace(s.begin(), s.begin() + 2, "NOI");
cout << "将字符串 s 的前两位替换为 NOI 后得到的字符串是 " << s << endl;


# 赋值操作
```
只记录下常见的：
void test1(){
    string str;
    str = "hello,world";
    cout << str;
}
void test2(){
    string str1;
    str1.assign("hello c++");
    cout << str1;
}
```

# 字符串拼接
```
void test3(){
    string str3 ="我";
    str3 += "爱学习";  //也可以strn1 + strn2;
    str4 = "肯定必须一定"
    str4.append(str3,4,2);//变成一定我爱学习
}
```

# 类型转换（C++11新增）

## 字符串与数值转换
以下函数需包含`<string>`头文件，支持进制转换和异常处理：

### 转换函数族
| 函数原型                  | 功能描述                     | 示例                     |
|---------------------------|------------------------------|--------------------------|
| `int stoi(const string&)`  | 字符串转 int                 | `stoi("42") → 42`        |
| `long stol(...)`           | 字符串转 long                | `stol("3e9") → 3000000000`|
| `float stof(...)`          | 字符串转 float               | `stof("3.14") → 3.14f`   |
| `double stod(...)`         | 字符串转 double              | `stod("2.718") → 2.718`  |
| `unsigned long stoul(...)` | 字符串转 unsigned long       | `stoul("4000000000") → 4e9` |



### 实用技巧
1. **进制转换**：
   ```cpp
   stoi("1010", nullptr, 2);  // 二进制 → 10
   stol("FF", nullptr, 16);   // 十六进制 → 255
   ```

2. **混合数据解析**：
   ```cpp
   string s = "ID:0x1A,Val:3.14";
   size_t pos = s.find("0x");//pos=3;
   int id = stoi(s.substr(pos), nullptr, 16);  // 解析十六进制
   ```
   **参数解析**：
    - `hex_part`：要转换的字符串 `"0x1A,Val:3.14"`。
    - `nullptr`：不接收处理结束位置。
    - `16`：按十六进制解析。
    *转换过程**：
    1. **跳过前缀**：自动忽略 `0x`（C++标准规定十六进制字符串可以带 `0x` 前缀）。
    2. **读取有效字符**：
    - 有效字符：`1`, `A`（十六进制允许 `A-F` 表示10-15）。
    - 遇到非十六进制字符 `,` 停止。
    3. **转换计算**：
    - `1A`（十六进制）→ `1*16 + 10 = 26`（十进制）。


```cpp
#include <string>

int num = 42;
double d = 3.14;

string s1 = to_string(num);  // "42"
string s2 = to_string(d);    // "3.140000"（精度可能不理想）
```
**特点**：
- 支持基本数值类型（int, long, double 等）
- 浮点数转换可能包含多余小数位
- 需要C++11或更高标准
---

### **2. 使用 `stringstream`（兼容性好）**
```cpp
#include <sstream>
#include <string>

template<typename T>
string to_string_ex(T value) {
    stringstream ss;
    ss << value;
    return ss.str();
}

// 使用示例
int num = 26;
double d = 3.1415926;
string s1 = to_string_ex(num);  // "26"
string s2 = to_string_ex(d);    // "3.14159"（保留默认精度）
```

**优势**：
- 支持自定义格式（如精度控制）
- 兼容C++98标准
- 可扩展性高（支持自定义类型）

**设置浮点数精度**：
```cpp
#include <iomanip>

double d = 3.1415926;
stringstream ss;
ss << fixed << setprecision(2) << d;  // 固定小数点，保留2位
string s = ss.str();  // "3.14"
```

### **实用技巧**
1. **浮点数保留两位小数**：
   ```cpp
   double d = 3.1415;
   stringstream ss;
   ss << fixed << setprecision(2) << d;  // "3.14"
   ```

2. **格式化十六进制输出**：
   ```cpp
   int num = 255;
   stringstream ss;
   ss << uppercase << hex << num;  // "FF"
   ```

3. **填充前导零**：
   ```cpp
   int num = 42;
   stringstream ss;
   ss << setw(5) << setfill('0') << num;  // "00042"
   ```

---

### **常见问题**
**Q：为什么 `to_string(3.14)` 得到 `"3.140000"`？**
- `to_string` 对浮点数的转换使用默认精度（通常6位小数），无法自动去除末尾零。

**Q：如何将布尔值转换为 `"true"/"false"`？**
- 使用三元运算符：
  ```cpp
  bool b = true;
  string s = b ? "true" : "false";
  ```