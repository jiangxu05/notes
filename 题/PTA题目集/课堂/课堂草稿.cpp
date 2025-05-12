// 输入格式:
// 从键盘上输入一个字符串s（最多80个字符）和一个待查找的字符ch，之间用回车分隔。

// 输出格式:
// 在串s中进行查找，如果找到了字符ch，则输出其所在位置的下标，如果找不到，则输出“查无此字符”的信息，最后换行。

// 输入样例1:
// abcdefg
// c

// 输出样例1:
// 2

// 输入样例2:
// 1234567890
// $


// 输出样例2:
// 查无此字符

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    char ch;
    cin >> s >> ch;
    int xiabiao = s.find(ch);
    if (xiabiao != string::npos) {
        cout << xiabiao << endl;
    } 
    else {
        cout << "查无此字符" << endl;
    }
    return 0;
}


// 编写程序，输入1个字符串，判断并输出该字符串是否是回文串。如果一个字符串从前往后和从后往前读的结果是一样的，该字符串称为回文，如“abcba”就是回文。

// 输入格式:
// 一个字符串（长度不超过99）

// 输出格式:
// 字符串是否为回文

// 输入样例1:
// abcba
// 输出样例1:
// abcba是回文
// 输入样例2:
// abc
// 输出样例2:
// abc不是回文

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    string s1 = s;
    reverse(s.begin(), s.end());
    if (s1 == s) {
        cout << s1 << "是回文" << endl;
    } 
    else {
        cout << s1 << "不是回文" << endl;
    }
    return 0;
}


// 个数统计：给定一个k位整数，请编写程序统计每种不同的数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。

// 输入格式:
// 每个输入包含1个测试用例，即一个不超过1000位的正整数N。

// 输出格式:
// 对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。

// 输入样例:
// 100311
// 输出样例:
// 0:2
// 1:3
// 3:1

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> count(10, 0);
    for (int i = 0; i < s.length(); i++) {
        count[s[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (count[i] != 0) {
            cout << i << ":" << count[i] << endl;
        }
    }
    return 0;
}

// D进制的A+B：输入两个非负10进制整数A和B，输出A+B的D (1 < D <= 10)进制数，即将十进制数A+B的和转换成D进制数输出。

// 输入格式:
// 输入在一行中依次给出3个整数A、B和D。

// 输出格式:
// 输出A+B的D进制数。

// 输入样例:
// 123 456 8
// 输出样例:
// 1103

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int a, b, d;
    cin >> a >> b >> d;
    int sum = a + b;
    vector<int> result;
    while (sum > 0) {
        result.push_back(sum % d);
        sum /= d;
    }
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    return 0;
}

// 一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：

// 首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；然后将计算的和对11取模得到值Z；最后按照以下关系对应Z值与校验码M的值：

// Z：0 1 2 3 4 5 6 7 8 9 10
// M：1 0 X 9 8 7 6 5 4 3 2
// 现在给定一些身份证号码，请你验证校验码的有效性，并输出有问题的号码。

// 输入格式：
// 输入第一行给出正整数N（≤100）是输入的身份证号码的个数。随后N行，每行给出1个18位身份证号码。

// 输出格式：
// 按照输入的顺序每行输出1个有问题的身份证号码。这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。如果所有号码都正常，则输出All passed。

// 输入样例1：
// 4
// 320124198808240056
// 12010X198901011234
// 110108196711301866
// 37070419881216001X
// 输出样例1：
// 12010X198901011234
// 110108196711301866
// 37070419881216001X
// 输入样例2：
// 2
// 320124198808240056
// 110108196711301862
// 输出样例2：
// All passed

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> ids(n);
    for (int i = 0; i < n; i++) cin >> ids[i];

    const int quanzhong[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    const char m[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    vector<string> errors;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < 17; j++) {
            sum += (ids[i][j] - '0') * quanzhong[j];
        }
        if (m[sum % 11] != ids[i][17]) {
            errors.push_back(ids[i]);
        }
    }
    if (errors.empty()) {
        cout << "All passed" << endl;
    }
    else {
        for (auto error : errors) cout << error << endl;
    }
    return 0;
}

// 本题要求编写程序，将给定字符串去掉重复的字符后，按照字符ASCII码顺序从小到大排序后输出。

// 输入格式：
// 输入是一个以回车结束的非空字符串（少于80个字符）。

// 输出格式：
// 输出去重排序后的结果字符串。

// 输入样例：
// ad2f3adjfeainzzzv
// 输出样例：
// 23adefijnvz

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s); // 使用getline读取整行，包括空格
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());//unique函数会返回一个迭代器，指向去重后的最后一个元素的下一个位置。
    cout << s << endl;
    return 0;
}
//unique函数用法：
//unique函数会返回一个迭代器，指向去重后的最后一个元素的下一个位置。
//unique函数会改变原数组，返回值是去重后的最后一个元素的下一个位置。
//unique函数会删除数组中的重复元素。
//unique函数会返回一个迭代器，指向去重后的最后一个元素的下一个位置。
//unique函数会删除数组中的重复元素。
//unique函数会返回一个迭代器，指向去重后的最后一个元素的下一个位置。
//std::unique只能移除连续的重复元素。如果输入是{1, 2, 1, 2}，直接调用std::unique不会有任何效果，因为重复的1和2不连续。排序后变为{1, 1, 2, 2}，此时std::unique可以正确去重。
// std::vector<int> v = {1, 2, 2, 3, 2, 1};
// std::sort(v.begin(), v.end()); // 排序后：{1, 1, 2, 2, 2, 3}
// auto last = std::unique(v.begin(), v.end()); // 去重后：{1, 2, 3, ...}
// v.erase(last, v.end()); // 实际删除多余元素

// RLE全称（run-length encoding），翻译为游程编码，又译行程长度编码，又称变动长度编码法，在控制论中对于二值图像而言是一种编码方法，对连续的黑、白像素数(游程)以不同的码字进行编码。游程编码是一种简单的非破坏性资料压缩法，其好处是加压缩和解压缩都非常快。RLE编码方式是用字符+字符连续出现次数来替代连续出现的字符，从而达到压缩的目的。

// 如ABBBBBBBBA的RLE编码为A1B8A1

// 输入格式:
// 从键盘输入一串字符（字符个数不超过80个）。

// 输出格式:
// 输出压缩后的RLE编码

// 输入样例:
// 在这里给出一组输入。例如：

// aaaaaaaaaaaab
// 输出样例:
// 在这里给出相应的输出。例如：

// a12b1

#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    getline(cin, s);//以后输入一行字符串，用getline
    string result;
    int count = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == s[i + 1]) {
            count++;
        }
        else {
            result += s[i] + to_string(count);
            count = 1;
        }
    }
    cout << result << endl;
    return 0;
}

// 越努力越幸运。这年诺诺读初三，3成为她的幸运数字，她光荣地加入了共青团。现在给你一串数字， 请找出其中的幸运数字（出现次数最多的那个数字，若有多个数字的出现次数都是最多，则为最大的那个数字）。

// 输入格式:
// 输入一串数字（长度不超过100）。

// 输出格式:
// 输出幸运数字。

// 输入样例:
// 320243315670920
// 输出样例:
// 3
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    vector<int> count(10, 0);
    vector<int> xingyunshu;
    for (size_t i = 0; i < s.length(); i++) {
        count[s[i] - '0']++;
    }
    int max_count = 0;
    for (int i = 0; i < 10; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
        }
    }
    for (int i = 0; i < 10; i++) {
        if (count[i] == max_count) {
            xingyunshu.push_back(i);
        }
    }
    cout << *max_element(xingyunshu.begin(), xingyunshu.end()) << endl;//这个*是解引用，返回的是一个指针
    return 0;
}

