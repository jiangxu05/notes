//  新浪微博上的一则趣闻，是瑞典斯德哥尔摩火车上的一道题，看上去是段伪代码：

// s = ''
// a = '1112031584'
// for (i = 1; i < length(a); i++) {
//   if (a[i] % 2 == a[i-1] % 2) {
//     s += max(a[i], a[i-1])
//   }
// }
// goto_url('www.multisoft.se/' + s)
// 其中字符串的 + 操作是连接两个字符串的意思。所以这道题其实是让大家访问网站 www.multisoft.se/112358（注意：比赛中千万不要访问这个网址！！！）。

// 当然，能通过上述算法得到 112358 的原始字符串 a 是不唯一的。本题就请你判断，两个给定的原始字符串，能否通过上述算法得到相同的输出？

// 输入格式：
// 输入为两行仅由数字组成的非空字符串，长度均不超过 10 
// 4
//  ，以回车结束。

// 输出格式：
// 对两个字符串分别采用上述斯德哥尔摩火车上的算法进行处理。如果两个结果是一样的，则在一行中输出那个结果；否则分别输出各自对应的处理结果，每个占一行。题目保证输出结果不为空。

// 输入样例 1：
// 1112031584
// 011102315849

// 输出样例 1：
// 112358
#include <iostream>
#include <string>
using namespace std;

// 获取结果:从原始字符串得到结果
string huoqu_jieguo(string yuanshi) {
    string jieguo = "";
    // 从第二个数字开始比较
    for(int i = 1; i < yuanshi.length(); i++) {
        // 转换字符串到数字来判断奇偶
        int dangqian_shuzi = yuanshi[i] - '0';
        int qian_shuzi = yuanshi[i-1] - '0';
        
        // 如果两个数字都是奇数或都是偶数
        if(dangqian_shuzi % 2 == qian_shuzi % 2) {
            // 找到较大的那个数字并加到结果里
            if(yuanshi[i] > yuanshi[i-1]) {
                jieguo += yuanshi[i];
            } else {
                jieguo += yuanshi[i-1];
            }
        }
    }
    return jieguo;
}

int main() {
    string zifuchuan1, zifuchuan2;
    getline(cin, zifuchuan1);
    getline(cin, zifuchuan2);
    
    // 获取两个字符串的结果
    string jieguo1 = huoqu_jieguo(zifuchuan1);
    string jieguo2 = huoqu_jieguo(zifuchuan2);
    
    // 如果结果相同,只输出一个
    if(jieguo1 == jieguo2) {
        cout << jieguo1 << endl;
    } else {
        // 否则输出两个结果
        cout << jieguo1 << endl;
        cout << jieguo2 << endl;
    }
    
    return 0;
}
