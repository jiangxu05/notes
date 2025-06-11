// 本题要求你实现一个程序，自动检查你朋友给你发来的信息里有没有 chi1 huo3 guo1。

// 输入格式：
// 输入每行给出一句不超过 80 个字符的、以回车结尾的朋友信息，信息为非空字符串，仅包括字母、数字、空格、可见的半角标点符号。当读到某一行只有一个英文句点 . 时，输入结束，此行不算在朋友信息里。

// 输出格式：
// 首先在一行中输出朋友信息的总条数。然后对朋友的每一行信息，检查其中是否包含 chi1 huo3 guo1，并且统计这样厉害的信息有多少条。在第二行中首先输出第一次出现 chi1 huo3 guo1 的信息是第几条（从 1 开始计数），然后输出这类信息的总条数，其间以一个空格分隔。题目保证输出的所有数字不超过 100。

// 如果朋友从头到尾都没提 chi1 huo3 guo1 这个关键词，则在第二行输出一个表情 -_-#。

// 输入样例 1：
// Hello!
// are you there?
// wantta chi1 huo3 guo1?
// that's so li hai le
// our story begins from chi1 huo3 guo1 le
// .

// 输出样例 1：
// 5
// 3 2
// 输入样例 2：
// Hello!
// are you there?
// wantta qi huo3 guo1 chi1huo3guo1?
// that's so li hai le
// our story begins from ci1 huo4 guo2 le
// .
#include <iostream>
#include <string>
using namespace std;

int main() {
    string xinxi; // 存储每行信息
    int zongxinxi = 0; // 总信息数
    int chihuo_count = 0; // 包含chi1 huo3 guo1的信息数
    int diyi_chihuo = -1; // 第一次出现的位置
    
    // 读取每行信息直到遇到"."
    while(getline(cin, xinxi) && xinxi != ".") {
        zongxinxi++;
        
        // 查找是否包含"chi1 huo3 guo1"
        // 需要确保chi1、huo3、guo1之间有空格分隔
        size_t pos = 0;
        while((pos = xinxi.find("chi1", pos)) != string::npos) {
            // 检查chi1后面是否跟着空格和huo3
            if(pos + 4 < xinxi.length() && 
               xinxi.substr(pos + 4, 1) == " " &&
               xinxi.substr(pos + 5, 4) == "huo3") {
                // 检查huo3后面是否跟着空格和guo1
                if(pos + 9 < xinxi.length() && 
                   xinxi.substr(pos + 9, 1) == " " &&
                   xinxi.substr(pos + 10, 4) == "guo1") {
                    chihuo_count++;
                    if(diyi_chihuo == -1) {
                        diyi_chihuo = zongxinxi;
                    }
                    break;
                }
            }
            pos++;
        }
    }
    
    // 输出结果
    cout << zongxinxi << endl;
    if(chihuo_count > 0) {
        cout << diyi_chihuo << " " << chihuo_count << endl;
    } else {
        cout << "-_-#" << endl;
    }
    
    return 0;
}
