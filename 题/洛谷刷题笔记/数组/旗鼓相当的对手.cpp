//现有 N 名同学参加了期末考试，并且获得了每名同学的信息：语文、数学、英语成绩（均为不超过 150 的自然数）。
//如果某对学生 ⟨i,j⟩ 的每一科成绩的分差都不大于 5，且总分分差不大于 10，那么这对学生就是“旗鼓相当的对手”。
//现在想知道这些同学中，有几对“旗鼓相当的对手”？同样一个人可能会和其他好几名同学结对。
//第一行一个正整数 N。接下来 N 行，每行三个整数，其中第 i 行表示第 i 名同学的语文、数学、英语成绩。最先读入的同学编号为 1。
//输出一个整数，表示“旗鼓相当的对手”的对数。

//计算成绩，循环比较，abs(a-b)<=5,abs(a-c)<=5,abs(b-c)<=5,abs(a+b+c-d-e-f)<=10
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    //表示一个二维的动态数组，即每个元素本身又是一个 vector<int>。
    //vector<int>(3)：创建一个包含 3 个 int 元素的 vector，初始值为 0。这个 vector 用来存储每个同学的三科成绩（语文、数学、英语）。
    //v(n, vector<int>(3))：创建一个包含 n 个元素的 vector，每个元素都是一个 vector<int>(3)。也就是说，v 是一个大小为 n 的二维 vector，
    //其中每个元素都是一个包含 3 个 int 的 vector。
//举例说明：
//假设 n = 3，那么 v 的结构如下：
//v = [
//    [0, 0, 0],  // 第 1 名同学的三科成绩
//    [0, 0, 0],  // 第 2 名同学的三科成绩
//    [0, 0, 0]   // 第 3 名同学的三科成绩
//    ]
    for (int i=0; i<n; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];//读入每个同学的三科成绩
    int ans=0;
    for (int i=0; i<n; i++)         //循环比较
        for (int j=i+1; j<n; j++){  
            int a=v[i][0], b=v[i][1], c=v[i][2], d=v[j][0], e=v[j][1], f=v[j][2];
            if (abs(a-d)<=5 && abs(b-e)<=5 && abs(c-f)<=5 && abs(a+b+c-d-e-f)<=10)
                ans++;
        }
    cout << ans;
    return 0;
}
