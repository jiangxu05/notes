// 曾经在天梯赛大杀四方的吉老师决定回归天梯赛赛场啦！

// 为了简化题目，我们不妨假设天梯赛的每道题目可以用一个不超过 500 的、只包括可打印符号的字符串描述出来，如：Problem A: Print "Hello world!"。

// 众所周知，吉老师的竞赛水平非常高超，你可以认为他每道题目都会做（事实上也是……）。因此，吉老师会按照顺序看题并做题。但吉老师水平太高了，所以签到题他就懒得做了（浪费时间），具体来说，假如题目的字符串里有 qiandao 或者 easy（区分大小写）的话，吉老师看完题目就会跳过这道题目不做。

// 现在给定这次天梯赛总共有几道题目以及吉老师已经做完了几道题目，请你告诉大家吉老师现在正在做哪个题，或者吉老师已经把所有他打算做的题目做完了。

// 提醒：天梯赛有分数升级的规则，如果不做签到题可能导致团队总分不足以升级，一般的选手请千万不要学习吉老师的酷炫行为！

// 输入格式：
// 输入第一行是两个正整数 N,M (1≤M≤N≤30)，表示本次天梯赛有 N 道题目，吉老师现在做完了 M 道。

// 接下来 N 行，每行是一个符合题目描述的字符串，表示天梯赛的题目内容。吉老师会按照给出的顺序看题——第一行就是吉老师看的第一道题，第二行就是第二道，以此类推。

// 输出格式：
// 在一行中输出吉老师当前正在做的题目对应的题面（即做完了 M 道题目后，吉老师正在做哪个题）。如果吉老师已经把所有他打算做的题目做完了，输出一行 Wo AK le。

// 输入样例 1：
// 5 1
// L1-1 is a qiandao problem.
// L1-2 is so...easy.
// L1-3 is Easy.
// L1-4 is qianDao.
// Wow, such L1-5, so easy.
// 输出样例 1：
// L1-4 is qianDao.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M; // 输入题目总数 N 和已做完的题目数 M

    vector<string> problems; // 存储所有题目
    vector<string> validProblems; // 存储吉老师会做的题目

    // 读取所有题目
    for (int i = 0; i < N; i++) {
        string problem;
        getline(cin >> ws, problem); // 读取一行题目（包括空格）
        //cin >> ws 会清除输入流中的空白字符，确保 getline 读取到正确的输入。
        problems.push_back(problem);
    }

    // 过滤吉老师会做的题目
    for (const string& problem : problems) {
        //const 表示 problem 是只读的，不能修改。
        //string& 表示 problem 是对容器中元素的引用，避免拷贝字符串的开销。
        //: 是范围 for 循环的语法符号。
        // 如果题目不包含 "qiandao" 和 "easy"，则加入 validProblems
        if (problem.find("qiandao") == string::npos && problem.find("easy") == string::npos) {
            //npos 是 std::string 的一个静态常量，表示一个无效的位置（通常是一个很大的值，比如 size_t 的最大值）。
            //当 find 未找到子字符串时，返回 npos。
            //如果题目中不包含 "qiandao" 和 "easy"，则将该题目加入 validProblems。

            validProblems.push_back(problem);
        }
    }

    // 判断吉老师是否已经做完所有题目
    if (M >= validProblems.size()) {
        cout << "Wo AK le" << endl;
    } else {
        cout << validProblems[M] << endl; // 输出当前正在做的题目
    }

    return 0;
}

//示例
//vector<string> problems = {"Problem A", "Problem B", "Problem C"};
//for (const string& problem : problems) {
//    cout << problem << endl;
//}
//Problem A
//Problem B
//Problem C