// 众所周知，在每一个彗星后都有一只 UFO。这些 UFO 时常来收集地球上的忠诚支持者。不幸的是，他们的飞碟每次出行都只能带上一组支持者。因此，他们要用一种聪明的方案让这些小组提前知道谁会被彗星带走。他们为每个彗星起了一个名字，通过这些名字来决定这个小组是不是被带走的那个特定的小组（你认为是谁给这些彗星取的名字呢？）。关于如何搭配的细节会在下面告诉你；你的任务是写一个程序，通过小组名和彗星名来决定这个小组是否能被那颗彗星后面的 UFO 带走。

// 小组名和彗星名都以下列方式转换成一个数字：最终的数字就是名字中所有字母的积，其中 A 是 1，Z 是 26。例如，USACO 小组就是 21×19×1×3×15=17955。如果小组的数字 mod47 等于彗星的数字 mod47,你就得告诉这个小组需要准备好被带走！（记住“amodb”是 a 除以 b 的余数，例如 34mod10 等于 4）

// 写出一个程序，读入彗星名和小组名并算出用上面的方案能否将两个名字搭配起来，如果能搭配，就输出 GO，否则输出 STAY。小组名和彗星名均是没有空格或标点的一串大写字母（不超过 6 个字母）。

// 输入格式
// 第1行：一个长度为 1 到 6 的大写字母串，表示彗星的名字。

// 第2行：一个长度为 1 到 6 的大写字母串，表示队伍的名字。

// 输出格式
// 无

// 输入输出样例
// 输入 #1复制

// COMETQ
// HVNGAT
// 输出 #1复制

// GO
// 输入 #2复制

// ABSTAR
// USACO
// 输出 #2复制

// STAY
#include <iostream>
#include <string>
using namespace std;

// 计算名字的乘积并取模47
int calculateMod(const string& name) {
    int product = 1;
    for (char c : name) {
        product *= (c - 'A' + 1);  // A=1, B=2,..., Z=26
    }
    return product % 47;
}

int main() {
    string comet, group;
    cin >> comet >> group;
    
    // 计算彗星和小组的模值
    int cometMod = calculateMod(comet);
    int groupMod = calculateMod(group);
    
    // 比较模值并输出结果
    if (cometMod == groupMod) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }
    
    return 0;
}
