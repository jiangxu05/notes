// 给定一个单词，请你输出它在给定的文章中出现的次数和第一次出现的位置。注意：匹配单词时，不区分大小写，但要求完全匹配，
//即给定单词必须与文章中的某一独立单词在不区分大小写的情况下完全相同（参见样例 1），如果给定单词仅是文章中某一单词的一部分则不算匹配（参见样例 2）。
// 输入格式
// 共 2 行。
// 第 1 行为一个字符串，其中只含字母，表示给定单词；
// 第 2 行为一个字符串，其中只可能包含字母和空格，表示给定的文章。

// 输出格式
// 一行，如果在文章中找到给定单词则输出两个整数，两个整数之间用一个空格隔开，分别是单词在文章中出现的次数和第一次出现的位置
//（即在文章中第一次出现时，单词首字母在文章中的位置，位置从 0 开始）；如果单词在文章中没有出现，则直接输出一个整数 −1。

// 注意：空格占一个字母位
// 输入输出样例
// 输入 #1复制

// To
// to be or not to be is a question
// 输出 #1复制
// 2 0

// 输入 #2复制
// to
// Did the Ottoman Empire lose its power at that time
// 输出 #2复制

// -1
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main() {
    string word, article;
    cin >> word;
    cin.ignore(); // 吸收换行符
    getline(cin, article);
    
   // 将单词和文章都转为小写以便比较
    for(char &c : word) c = tolower(c);
    for(char &c : article) c = tolower( c);
    
    int count = 0, firstPos = -1;
    int pos = 0;
    
    while(pos < article.length()) {
        // 找到单词的起始位置
        while(pos < article.length() && !isalpha(article[pos])) pos++;
        
        int wordStart = pos;
        // 找到单词的结束位置
        while(pos < article.length() && isalpha(article[pos])) pos++;
        
        // 截取当前单词
        string curWord = article.substr(wordStart, pos - wordStart);
        
        // 比较是否匹配
        if(curWord == word) {
            count++;
            if(firstPos == -1) firstPos = wordStart;
        }
    }
    
    if(count > 0) {
        cout << count << " " << firstPos;
    } else {
        cout << -1;
    }
    
    return 0;
}

//note：自己写了几次，交了几次，问题有：
//1.读取文章没有用getline读入空格
//2.循环语句的判断不知道什么时候用等于，小于等于，
//    - 结合本题的while循环解释：
//      * 在第一个while循环中：while(pos < article.length())
//        - 这里用 < 而不是 <= 是因为字符串的索引从0开始
//        - 比如文章长度是10，有效索引是0-9
//        - 当pos=10时，已经超出范围，不应该再进入循环
//      * 在第二个while循环中：while(pos < article.length() && !isalpha(article[pos]))
//        - 同样用 < 来确保不会访问到不存在的字符
//        - 比如文章是"hello world"，长度是11
//        - 当pos=11时，article[11]是无效访问
//      * 在第三个while循环中：while(pos < article.length() && isalpha(article[pos]))
//        - 用 < 来安全地遍历每个字母
//        - 当遇到空格或字符串结尾时停止
//      * 总结：在遍历字符串时，总是用 < length() 来确保不会越界访问
//3.tolower函数没有赋值：c = ；并且不能加const