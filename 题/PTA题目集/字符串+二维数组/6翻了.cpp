//“666”是一种网络用语，大概是表示某人很厉害、我们很佩服的意思。最近又衍生出另一个数字“9”，意思是“6翻了”，实在太厉害的意思。如果你以为这就是厉害的最高境界，那就错啦 —— 目前的最高境界是数字“27”，因为这是 3 个 “9”！
//本题就请你编写程序，将那些过时的、只会用一连串“6666……6”表达仰慕的句子，翻译成最新的高级表达。
//输入格式：
//输入在一行中给出一句话，即一个非空字符串，由不超过 1000 个英文字母、数字和空格组成，以回车结束。
//输出格式：
//从左到右扫描输入的句子：如果句子中有超过 3 个连续的 6，则将这串连续的 6 替换成 9；但如果有超过 9 个连续的 6，则将这串连续的 6 替换成 27。其他内容不受影响，原样输出。
//输入样例：
//it is so 666 really 6666 what else can I say 6666666666
//输出样例：
//it is so 666 really 9 what else can I say 27

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    int count = 0;
    int start = -1;
    
    for(int i = 0; i <= s.length(); i++) {
        //小于等于而不是小于
        if(i < s.length() && s[i] == '6') {
            if(count == 0) start = i;
            count++;
        } else {
            if(count > 9) {
                s.replace(start, count, "27");
            } else if(count > 3) {
                s.replace(start, count, "9"); //这里一定是双引号？
            }
            count = 0;
        }
    }
    
    cout << s << endl;
    return 0;
}
//以上仅有14，有一个测试点没过，以下满分

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int pos = 0;
    int cnt = 0;
//这是因为循环的逻辑在遇到非 '6' 字符时才会处理之前的连续 '6'。如果字符串以连续的 '6' 结尾，循环结束后这些 '6' 就不会被处理。
    for (size_t i = 0; i < s.length(); i++) { // 修改为 i < s.length()
        if (s[i] == '6') {
            if (cnt == 0) pos = i; // 记录连续 '6' 的起始位置
            cnt++;
        } else {
            if (cnt > 9) {
                s.replace(pos, cnt, "27"); // 替换为 "27"
                i = pos + 1; // 调整 i 的位置，因为字符串长度可能变化
            } else if (cnt > 3) {
                s.replace(pos, cnt, "9"); // 替换为 "9"
                i = pos; // 调整 i 的位置，因为字符串长度可能变化
            }
            cnt = 0; // 重置计数器
        }
    }

    // 处理字符串末尾的连续 '6'
    if (cnt > 9) {
        s.replace(pos, cnt, "27");
    } else if (cnt > 3) {
        s.replace(pos, cnt, "9");
    }

    cout << s << endl;
    return 0;
}