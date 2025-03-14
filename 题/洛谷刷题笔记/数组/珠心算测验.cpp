// 珠心算是一种通过在脑中模拟算盘变化来完成快速运算的一种计算技术。珠心算训练，既能够开发智力，又能够为日常生活带来很多便利，因而在很多学校得到普及。

// 某学校的珠心算老师采用一种快速考察珠心算加法能力的测验方法。他随机生成一个正整数集合，集合中的数各不相同，然后要求学生回答：其中有多少个数，恰好等于集合中另外两个（不同的）数之和？

// 最近老师出了一些测验题，请你帮忙求出答案。

// 输入格式
// 共两行，第一行包含一个整数 n，表示测试题中给出的正整数个数。

// 第二行有 n 个正整数，每两个正整数之间用一个空格隔开，表示测试题中给出的正整数。

// 输出格式
// 一个整数，表示测验题答案。

// 输入输出样例
// 输入 #1复制

// 4
// 1 2 3 4
// 输出 #1复制
//2

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int shuzi_geshu; // 输入的数字个数
    cin >> shuzi_geshu;
    
    vector<int> shuzu(shuzi_geshu); // 存储输入的数字
    for(int i = 0; i < shuzi_geshu; i++) {
        cin >> shuzu[i];
    }
    
    int jieguo = 0; // 符合条件的数字个数
    
    // 遍历每个数字,检查它是否等于其他两个数之和
    for(int i = 0; i < shuzi_geshu; i++) {
        // 遍历所有可能的两数组合
        for(int j = 0; j < shuzi_geshu; j++) {
            for(int k = j + 1; k < shuzi_geshu; k++) {
                // 跳过当前检查的数字
                if(i == j || i == k) continue;
                
                // 如果找到两个数之和等于当前数
                if(shuzu[j] + shuzu[k] == shuzu[i]) {
                    jieguo++;
                    break; // 找到一组就可以跳出内层循环
                }
            }
        }
    }
    
    cout << jieguo << endl;
    return 0;
}