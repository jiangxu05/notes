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
#include <string>
using namespace std;

int main() {
    int zongti, yizuo; // 总题数和已做题数
    cin >> zongti >> yizuo;
    cin.ignore(); // 忽略换行符
    
    string timu; // 存储每道题目
    int yijing_zuo = 0; // 已经做的题目数
    int dangqian = 0; // 当前看到第几题
    
    while(getline(cin, timu)) {
        dangqian++;
        
        // 检查是否包含qiandao或easy
        bool tiaoguo = false;
        string xiaoxie = timu;
        // 转换为小写进行检查
        for(int i = 0; i < xiaoxie.length(); i++) {
            if(xiaoxie[i] >= 'A' && xiaoxie[i] <= 'Z') {
                xiaoxie[i] = tolower(xiaoxie[i]);
            }
        }
        if(xiaoxie.find("qiandao") != string::npos || 
           xiaoxie.find("easy") != string::npos) {
            tiaoguo = true;
        }
        
        // 如果不是签到题就做
        if(!tiaoguo) {
            yijing_zuo++;
            // 如果做的题目数等于要求的数量,输出下一题
            if(yijing_zuo == yizuo) {
                // 继续找下一个非签到题
                while(dangqian < zongti) {
                    getline(cin, timu);
                    dangqian++;
                    // 检查下一题是否为签到题
                    xiaoxie = timu;
                    for(int i = 0; i < xiaoxie.length(); i++) {
                        if(xiaoxie[i] >= 'A' && xiaoxie[i] <= 'Z') {
                            xiaoxie[i] = tolower(xiaoxie[i]);
                        }
                    }
                    // string::npos是一个特殊值,表示"没有找到"
                    // find()函数在找不到子串时会返回string::npos
                    // 所以 find() == string::npos 意味着没找到这个子串
                    // find() != string::npos 意味着找到了这个子串
                    if(xiaoxie.find("qiandao") == string::npos && // 如果没找到"qiandao"
                       xiaoxie.find("easy") == string::npos) {     // 并且没找到"easy"
                        cout << timu << endl;
                        return 0;
                    }
                }
                cout << "Wo AK le" << endl;
                return 0;
            }
        }
    }
    
    cout << "Wo AK le" << endl;
    return 0;
}
