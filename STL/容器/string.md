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
    str4 = "肯定必须一定“;
    str4.append(str3,4，2);//变成一定我爱学习
}
```