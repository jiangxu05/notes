// 题目描述
// 2013 年 X 月 X 日，俄罗斯办理了斯诺登的护照，于是他混迹于一架开往委内瑞拉的飞机。但是，这件事情太不周密了，因为 FBI 的间谍早已获悉他的具体位置——但这不是最重要的——最重要的是如果要去委内瑞拉，那么就要经过古巴，而经过古巴的路在美国的掌控之中。

// 丧心病狂的奥巴马迫降斯诺登的飞机，搜查时却发现，斯诺登杳无踪迹。但是，在据说是斯诺登的座位上，发现了一张纸条。纸条由纯英文构成：Obama is a two five zero.（以 . 结束输出，只有 6 个单词+一个句号，句子开头如没有大写亦为合法）这句话虽然有点无厘头，但是警官陈珺骛发现这是一条极其重要的线索。他在斯诺登截获的一台笔记本中找到了一个 C++ 程序，输入这条句子后立马给出了相对应的密码。陈珺鹜高兴得晕了过去，身为警官的你把字条和程序带上了飞机，准备飞往曼哈顿国际机场，但是在飞机上检查的时候发现——程序被粉碎了！飞机抵达华盛顿只剩 5 分钟，你必须在这 5 分钟内编写（杜撰）一个程序，免受上司的 10000000000mod10 大板。破译密码的步骤如下：

// （1）找出句子中所有用英文表示的数字 (≤20)，列举在下：

// 正规：one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen             twenty

// 非正规：a both another first second third。为避免造成歧义，another 算作 1 处理。

// （2）将这些数字平方后对 100 取模，如 00,05,11,19,86,99。

// （3）把这些两位数按数位排成一行，组成一个新数，如果开头为 0，就去 0。

// （4）找出所有排列方法中最小的一个数，即为密码。

// // 数据已经修正 By absi2011 如果还有问题请联系我

// 输入格式
// 一个含有 6 个单词的句子。

// 输出格式
// 一个整型变量（密码）。如果没有符合要求的数字出现，则输出 0。

// 输入输出样例
// 输入 #1复制

// Black Obama is two five zero .
// 输出 #1复制

// 425
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 定义数字映射
    string numWords[] = {"one", "two", "three", "four", "five", "six", "seven", 
                        "eight", "nine", "ten", "eleven", "twelve", "thirteen", 
                        "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", 
                        "nineteen", "twenty", "a", "both", "another", "first", "second", "third"};
    int numValues[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,1,2,1,1,2,3};
    
    vector<int> nums;
    string word;
    while (cin >> word && word != ".") {
        // 转换为小写
        for (char &c : word) c = tolower(c);
        // 查找是否为数字
        for (int i = 0; i < 26; i++) {
            if (word == numWords[i]) {
                int num = (numValues[i] * numValues[i]) % 100;
                nums.push_back(num);
                break;
            }
        }
    }
    
    // 排序并拼接
    sort(nums.begin(), nums.end());
    string password;
    for (int num : nums) {
        if (num < 10) password += '0';  // 补零
        password += to_string(num);
    }
    
    // 去除前导零
    password.erase(0, password.find_first_not_of('0'));
    cout << (password.empty() ? "0" : password) << endl;
    
    return 0;
}

