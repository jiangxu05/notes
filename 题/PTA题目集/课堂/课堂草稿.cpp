// 二分
int fun(int a[], int n, int key) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // 防止溢出
        if (a[mid] == key) {
            return mid;
        } else if (a[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

//本题要求实现一个函数，删去给定非负整数数组中的重复整数（整数数值不超过100）
//不重复的元素放于原数组中，不要改变原来的次序。该函数返回不重复的整数个数。
//接口定义：
//函数原型为：
//int Unique_Int (int a[], int n );
//其中 a[ ] 是输入的整数数组， n 是整数个数(0<=n&&n<=100)。 函数须返回 a中不重复的整数个数，删除重复的整数(仅保留第一个)，依然存于数组a中。

//裁判测试程序样例：
#include <iostream>
using namespace std;
int Unique_Int (  int a[ ], int n );

int main()
{
  int a[100], n, i, count;
  cin>>n;
  for(i=0; i<n; i++)
    cin>>a[i];
  count=Unique_Int(a,n); 
  cout<<count<<endl;
  for(i=0; i<count; i++)
   cout<<a[i]<<" ";
  return 0;
}

/* 请在这里填写答案 */
int Unique_Int(int a[], int n) {
    if (n == 0) return 0;
    
    int j = 0; // 指向当前不重复元素的位置
    
    for (int i = 0; i < n; i++) {
        bool is_unique = true;
        
        // 检查a[i]是否在a[0..j-1]中出现过
        for (int k = 0; k < j; k++) {
            if (a[k] == a[i]) {
                is_unique = false;
            }
        }
        
        // 如果是唯一的，保留它
        if (is_unique) {
            a[j] = a[i];
            j++;
        }
    }
    
    return j;
}


//数组拼接
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int la,lb;
    cin >> la;
    vector<int> shuzu(la);
    for(int i = 0; i < la; i++){
        cin >> shuzu[i];
    }
    cin >> lb;
    for(int i = 0; i < lb; i++){
        int temp;
        cin >> temp;
        shuzu.push_back(temp);
    }
    sort(shuzu.begin(),shuzu.end());

    for(size_t i= 0; i < shuzu.size();i++){
        cout << shuzu[i]<<" ";
    }
    return 0;
}


// 数值排序
// 分数 10
// 作者 肖奕
// 单位 中国地质大学（北京）
// 一个非负整数n（长整型），将其各个位上的数字按升序排列，组成一个新数。注意:正整数的首位不为0.

// 输入格式:
// 在一行里输入一个非负整数n

// 输出格式:
// 输入程序排列后的整数。

// 输入样例:
// 在这里给出一组输入。例如：

// 265123

// 输出样例:
// 在这里给出相应的输出。例如：

// 122356
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    sort(str.begin(),str.end());
    if (str[0] == '0') {
        size_t pos = str.find_first_not_of('0');
        if (pos != string::npos) {
            str = str.substr(pos);
        }
    }
    cout << str;
    return  0;
}

// 7-3 疑？悟？
// 分数 10
// 作者 苏国煜
// 单位 闽江学院
// “All your efforts will pay off.”
// 在闽江学院的程序设计金课和算法集训队的开课时间内，每周都会进行一场紧张刺激的周小测，每次小测都会准备n道题目，同学们可以在小测结束前解决这些题目。在小测结束并听完讲解后，题目集会重新开放，同学们可以继续补题，要想能在程序设计金课和算法集训队里有更多的收获，就需要尽量多地解决出题目集的题目。

// 每道题目在解决时可以获得两种经验值： a 
// i
// ​
//  ​ 和 b 
// i
// ​
//  ​ ​，若同学能够在小测结束前解决出这道题目，就能获得经验值 a 
// i
// ​
//  ​ ​；若同学在小测结束并听完讲解后解决出这道题目，就能获得经验值  b 
// i
// ​
//  ​；若同学不能解决题目，就无法经验值。

// 我们规定，若一个同学解决一次小测的n道题所获得的经验值小于本次小测所能获得最高经验值（即∑ 
// i=1
// n
// ​
//  a 
// i
// ​
//  ）的 50% ，代表这位同学对本次小测有疑惑，否则代表该同学对本次小测的知识点都领悟了。

// 输入格式:
// 输入共有4行。
// 第一行，输入一个整数n，表示一次小测题目的数量。
// 第二行，n个整数，表示 a 
// 1
// ​
//  ,a 
// 2
// ​
//  ,…,a 
// n
// ​
//   ，即每道题目在小测结束之前解决出来获得的经验值。
// 第三行，n个整数，表示 b 
// 1
// ​
//  ,b 
// 2
// ​
//  ,…,b 
// n
// ​
//   ，即每道题目在小测结束之后解决出来获得的经验值。
// 第四行，n个整数，只可能是0、1和2，代表每道题的状态，0 表示最终不能解决该题目，1表示在小测结束前就解决出题目，2表示在小测结束后解决出题目。请你判断该同学对本次小测是否有疑惑。

// 输出格式:
// 若该同学对本次小测感到疑惑，则输出一个疑，否则输出一个悟。

// 输入样例1:
// 5
// 5 10 5 20 10
// 1 10 5 2 10
// 2 0 1 2 0
// 输出样例1:
// 疑
// 输入样例2:
// 5
// 10 10 20 20 30
// 10 10 10 20 20
// 1 1 2 2 0
// 输出样例2:
// 悟

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    double key = 0;
    cin >> n;
    int jingyana(n);
    for(int i = 0; i < n; i++){
        cin >> jingyana[i];
        key+=jingyana[i];
    }
    int jingyanb(n);
    for(int i = 0; i < n; i++) cin >> jingyanb[i];
    int zhuangtai(n);
    for(int i = 0; i < n; i++) cin >> zhuangtai[i];
    
    key /= 2.0;

    int jingyan = 0;

    for(int i = 0;i < n; i++){
        if(zhuangtai[i] == 1){
            jingyan += jingyana[i];
            break;
            }
        else if(zhuangtai[i] == 2){
            jingyan += jiangyanb[i];
            break;
            }
        }

    if(jingyan < key) cout << "疑" << endl;
    else coutc << "悟"<<endl;
    
    return 0;
}