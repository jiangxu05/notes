//- 例如 679 的持续性就是 5，因为我们从 679 开始，得到 6×7×9=378，随后得到 3×7×8=168、1×6×8=48、4×8=32，最后得到 3×2=6，一共用了 5 步。
//- 输入在一行中给出两个正整数 a 和 b（1≤a≤b≤10^9且 (b−a)<10^3），为给定区间的两个端点。
//- 首先在第一行输出区间 [a,b] 内整数最长的持续性。随后在第二行中输出持续性最长的整数。如果这样的整数不唯一，则按照递增序输出，数字间以 1 个空格分隔，行首尾不得有多余空格。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 计算一个数的持续性
int chixuxing(int num) {
    int steps = 0;
    while (num >= 10) { // 当 num 不是单个数字时继续
        int jieguo = 1;
        while (num > 0) { // 计算各位数字的乘积
            jieguo *= num % 10;
            num /= 10;
        } //反正就记住除10去掉个位，模10取个位
        num = jieguo; // 更新 num 为乘积
        steps++; // 增加步骤数
    }
    return steps;
}

int main() {
    int a, b;
    cin >> a >> b; // 输入区间 [a, b]
    int maxLen = 0; // 记录最大持续性
    vector<int> zuidachixushu; // 记录具有最大持续性的数

    for (int i = a; i <= b; i++) {
        int chixushu = chixuxing(i); // 计算当前数的持续性
        if (chixushu > maxLen) {
            maxLen = chixushu; // 更新最大持续性
            zuidachixushu.clear(); // 清空之前的记录
            zuidachixushu.push_back(i); // 添加当前数
        } else if (chixushu == maxLen) {
            zuidachixushu.push_back(i); // 如果持续性相同，添加到记录中
        }
    }

    // 输出结果
    cout << maxLen << endl; // 输出最大持续性
    for (int i = 0; i < zuidachixushu.size(); i++) {
        cout << zuidachixushu[i];
        if (i != zuidachixushu.size() - 1) {//最后一个数后面不加空格
            cout << " "; // 数字间用空格分隔
        }
    }
    return 0;
}


//，你会得到一段由大小写字母、数字、空格及 ASCII 码范围内的标点符号的文字，以及若干个违禁词以及警告阈值，你需要首先检查内容里有多少违禁词，
//如果少于阈值个，则简单地将违禁词替换为<censored>；如果大于等于阈值个，则直接输出一段警告并输出有几个违禁词。
//输入第一行是一个正整数 N (1≤N≤100)，表示违禁词的数量。接下来的 N 行，每行一个长度不超过 10 的、只包含大小写字母、数字及 ASCII 码范围内的标点符号的单词，表示应当屏蔽的违禁词。
//然后的一行是一个非负整数 k (0≤k≤100)，表示违禁词的阈值。最后是一行不超过 5000 个字符的字符串，表示需要检查的文字。
//从左到右处理文本，违禁词则按照输入顺序依次处理；对于有重叠的情况，无论计数还是替换，查找完成后从违禁词末尾继续处理。
//如果违禁词数量小于阈值，则输出替换后的文本；否则先输出一行一个数字，表示违禁词的数量，然后输出He Xie Ni Quan Jia!。
//输入样例1:
//5
//MaoNiang
//SeQing
//BaoLi
//WeiGui
//BuHeShi
//4
//BianCheng MaoNiang ba! WeiGui De Hua Ye Keyi Shuo! BuYao BaoLi NeiRong.
//输出样例1:
//BianCheng <censored> ba! <censored> De Hua Ye Keyi Shuo! BuYao <censored> NeiRong.

//输入：向量存储违禁词，一行字符串用getline；查找：text.find(word, pos)；替换：text.replace(pos, word.length(), "<censored>")
//本题学了啥？cin.ignore();getline(cin,text);const tring& word : weijinci;
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> weijinci(n);
    for (int i = 0; i < n; ++i) {
        cin >> weijinci[i];
    }

    int k;
    cin >> k;

    cin.ignore(); // 忽略换行符，在读取完一个整数或字符串后，输入缓冲区中可能会留下一个换行符（\n），如果不处理，会影响后续的输入（比如 getline）。
    string text;
    getline(cin, text);//读取一行字符串，与 cin >> 不同，cin >> 会忽略空格和换行符，而 getline 会读取整行内容。包括空格，直到遇到换行符为止。

    int count = 0;
    for (const string& word : weijinci) {
        //用于遍历容器（如 vector、array 等）中的每个元素。const string& word 表示每次循环时，word 是 bannedWords 中当前元素的常量引用（避免拷贝，提高效率）。
        //const string& 表示只读引用，避免拷贝字符串，提高性能。

        size_t pos = 0;
        //表示大小或索引的无符号整数类型。string::find 和 string::replace 等函数返回的索引值通常是 size_t 类型。
        while ((pos = text.find(word, pos)) != string::npos) {
            //string::npos 是一个常量，表示未找到。
            //text 中查找子串 word，从位置 pos 开始查找。text.find(word, pos) 返回子串 word 在 text 中第一次出现的位置（索引），如果没找到则返回 string::npos。
            text.replace(pos, word.length(), "<censored>");
            pos += 10; // "<censored>" 的长度ce
            //见隔壁的md笔记STL的vector。
            count++;
        }
    }

    if (count >= k) {
        cout << count << endl;
        cout << "He Xie Ni Quan Jia!" << endl;
    } else {
        cout << text << endl;
    }

    return 0;
}

//将一个 9×9 的正方形区域划分为 9 个 3×3 的正方形宫位，要求 1 到 9 这九个数字中的每个数字在每一行、每一列、每个宫位中都只能出现一次。
//本题并不要求你写程序解决这个问题，只是对每个填好数字的九宫格，判断其是否满足游戏规则的要求。
//输入首先在第一行给出一个正整数 n（≤10），随后给出 n 个填好数字的九宫格。每个九宫格分 9 行给出，每行给出 9 个数字，其间以空格分隔。
//对每个给定的九宫格，判断其中的数字是否满足游戏规则的要求。满足则在一行中输出 1，否则输出 0。
//难点，每行每列的检索，
//二维向量存储，数组存贮结果，假设所有满足；读取九宫格；
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> jiugongge(9, vector<int>(9));
    vector<int> ans(n, 1); // 初始化结果为1，假设所有九宫格都满足规则

    for(int i = 0; i < n; i++){
        // 读取九宫格
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
                cin >> jiugongge[j][k];
            }
        }

        // 检查每行
        for(int j = 0; j < 9; j++){
            vector<int> row(9, 0);
            for(int k = 0; k < 9; k++){
                row[jiugongge[j][k]-1]++;
            }
            if(find(row.begin(), row.end(), 2) != row.end()){
                //这里的 2 表示某个数字在当前行中出现了两次。注意之前的row(9,0)表示9个0;
                ans[i] = 0;
                break;
            }
        }

        // 如果行检查已经失败，跳过列和宫位检查
        if(ans[i] == 0) continue;//continue 的作用是跳过当前循环的剩余部分，直接进入下一次循环。

        // 检查每列
        for(int j = 0; j < 9; j++){
            vector<int> col(9, 0);
            for(int k = 0; k < 9; k++){
                col[jiugongge[k][j]-1]++;
            }
            if(find(col.begin(), col.end(), 2) != col.end()){
                ans[i] = 0;
                break;
            }
        }

        // 如果列检查已经失败，跳过宫位检查
        if(ans[i] == 0) continue;

        // 检查每个宫位
        //内层两个循环（x 和 y）用于遍历当前宫位的每个单元格。
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                vector<int> block(9, 0);
                for(int x = 0; x < 3; x++){
                    for(int y = 0; y < 3; y++){
                        block[jiugongge[j*3+x][k*3+y]-1]++;
                    }
                }
                if(find(block.begin(), block.end(), 2) != block.end()){
                    ans[i] = 0;
                    break;
                }
            }
            if(ans[i] == 0) break;
        }
    }

    // 输出结果
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }

    return 0;
}

