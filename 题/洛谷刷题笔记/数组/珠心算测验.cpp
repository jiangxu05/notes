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
                //具体来说，当 i == j 或 i == k 时，continue 会跳过当前 k 循环的剩余部分，直接进入下一次 k 循环的迭代。这是因为 continue 语句只会影响它所在的最内层循环。


                
                // 如果找到两个数之和等于当前数
                if(shuzu[j] + shuzu[k] == shuzu[i]) {
                    jieguo++;
                    break; // 找到一组就可以跳出内层循环
                    //如果没有 break，程序会继续检查 j = 0，k = 2 等其他组合，但这些组合要么不满足条件，要么是重复的，增加了不必要的计算。
                }
            }
        }
    }
    
    cout << jieguo << endl;
    return 0;
}
/*
问题分析:
1. 当前代码的主要问题是在找到一组满足条件的组合后,只跳出了最内层的k循环,
   但j循环还在继续。这可能导致同一个数被重复计算多次。

2. 例如对于输入: 4 1 2 3 4
   当检查数字3时:
   - 找到1+2=3,计数加1
   - 由于只break了k循环,j循环继续
   - 可能又找到其他组合(如2+1=3),导致重复计数

3. 解决方案:
   - 在找到一组满足条件的组合后,应该直接跳出j和k的双重循环
   - 使用标志变量实现
*/

// 修正后的代码:
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int shuzi_geshu;
    cin >> shuzi_geshu;
    
    vector<int> shuzu(shuzi_geshu);
    for(int i = 0; i < shuzi_geshu; i++) {
        cin >> shuzu[i];
    }
    
    int jieguo = 0;
    
    for(int i = 0; i < shuzi_geshu; i++) {
        bool found = false;  // 标志变量
        //在 j 和 k 循环的条件中，加入了 && !found。
        //如果 found 为 true，则 !found 为 false，循环条件不满足，内层循环会立即终止。
        //这样可以避免在找到满足条件的组合后，继续检查其他不必要的组合。
        for(int j = 0; j < shuzi_geshu && !found; j++) {
            if(i == j) continue;
            for(int k = j + 1; k < shuzi_geshu && !found; k++) {
                if(i == k) continue;
                
                if(shuzu[j] + shuzu[k] == shuzu[i]) {
                    jieguo++;
                    found = true;  // 设置标志并跳出所有内层循环
                }
            }
        }
    }
    
    cout << jieguo << endl;
    return 0;
}

