// 微博上有个自称“大笨钟V”的家伙，每天敲钟催促码农们爱惜身体早点睡觉。为了增加敲钟的趣味性，还会糟改几句古诗词。其糟改的方法为：去网上搜寻压“ong”韵的古诗词，把句尾的三个字换成“敲笨钟”。例如唐代诗人李贺有名句曰：“寻章摘句老雕虫，晓月当帘挂玉弓”，其中“虫”（chong）和“弓”（gong）都压了“ong”韵。于是这句诗就被糟改为“寻章摘句老雕虫，晓月当帘敲笨钟”。

// 现在给你一大堆古诗词句，要求你写个程序自动将压“ong”韵的句子糟改成“敲笨钟”。

// 输入格式：
// 输入首先在第一行给出一个不超过 20 的正整数 N。随后 N 行，每行用汉语拼音给出一句古诗词，分上下两半句，用逗号 , 分隔，句号 . 结尾。相邻两字的拼音之间用一个空格分隔。题目保证每个字的拼音不超过 6 个字符，每行字符的总长度不超过 100，并且下半句诗至少有 3 个字。

// 输出格式：
// 对每一行诗句，判断其是否压“ong”韵。即上下两句末尾的字都是“ong”结尾。如果是压此韵的，就按题面方法糟改之后输出，输出格式同输入；否则输出 Skipped，即跳过此句。

// 输入样例：
// 5
// xun zhang zhai ju lao diao chong, xiao yue dang lian gua yu gong.
// tian sheng wo cai bi you yong, qian jin san jin huan fu lai.
// xue zhui rou zhi leng wei rong, an xiao chen jing shu wei long.
// zuo ye xing chen zuo ye feng, hua lou xi pan gui tang dong.
// ren xian gui hua luo, ye jing chun shan kong.
// 输出样例：
// xun zhang zhai ju lao diao chong, xiao yue dang lian qiao ben zhong.
// Skipped
// xue zhui rou zhi leng wei rong, an xiao chen jing qiao ben zhong.
// Skipped
// Skipped
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // 忽略换行符
    
    // 处理N行输入
    for(int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        
        // stringstream是一个字符串流类,可以像处理输入输出流一样处理字符串
        // 常用于字符串分割等操作
        // 语法:
        // stringstream ss; // 创建空的字符串流
        // stringstream ss(str); // 用字符串str初始化
        // ss >> var; // 从流中读取数据到变量var
        // ss << var; // 将变量var写入流
        // getline(ss, str, delim); // 从流中读取直到遇到delim分隔符
        
        // 例如对于字符串 "hello,world"
        // stringstream ss("hello,world");
        // string s1, s2;
        // getline(ss, s1, ','); // s1 = "hello"
        // getline(ss, s2); // s2 = "world"
        
        stringstream ss(line);
        string first_half, second_half;
        getline(ss, first_half, ','); // 读取直到逗号的内容到first_half
        getline(ss, second_half, '.'); // 读取直到句号的内容到second_half
        
        // 从后向前找到上半句最后一个词
        string last_word_first = "";
        stringstream ss1(first_half);
        string word;
        while(ss1 >> word) {
            last_word_first = word;
        }
        
        // 从后向前找到下半句最后一个词
        string last_word_second = "";
        stringstream ss2(second_half);
        while(ss2 >> word) {
            last_word_second = word;
        }
        
        // 检查是否都以ong结尾
        if(last_word_first.length() >= 3 && 
           last_word_second.length() >= 3 &&
           last_word_first.substr(last_word_first.length()-3) == "ong" &&
           last_word_second.substr(last_word_second.length()-3) == "ong") {
            
            // 找到下半句最后三个词的起始位置
            int count = 0;
            int pos = second_half.length() - 1;
            while(pos >= 0 && count < 3) {
                if(second_half[pos] == ' ') count++;
                pos--;
            }
            
            // 替换最后三个词为"qiao ben zhong"
            cout << first_half << "," << second_half.substr(0, pos+2) 
                 << "qiao ben zhong." << endl;
        } else {
            cout << "Skipped" << endl;
        }
    }
    return 0;
}
