//没想到循环还可以这么玩,my answer:
#include<iostream>
using namespace std;
int main(){
    int x,n,ans=0;  //题目比较狗 n达到六次方了都，所以用long long
    cin>>x>>n;
    for(int i=0;i<n;i++){
        if(x >=1 && x<6){
            ans+=250;
        }

        x++;

        if(x>7) x=1;//为什么这里不能写else if：因为x=6的时候，不会进入第一个if，所以x++，然后x=7，然后进入第二个if，x=1
        
    }
    cout<<ans<<endl;
    return 0;
}
//变量声明问题：在 int x, ans = 0; 这一行，ans 被正确地初始化为 0，但是 x 没有被初始化。尽管 x 会在之后的 cin >> x >> n; 被赋值，但是良好的编程习惯是在声明时初始化所有变量。
//条件判断问题：在 if(x != 6 && x != 7) 条件下，只有当 x 不是 6 或 7 时，ans 才会增加 250。然而，当 x 为 6 时，代码没有递增 x，这会导致一个无限循环，因为 x 将永远保持为 6，循环将不会继续。
//更新 x 的逻辑：在 else if(x == 7) 和 else x++; 中，您没有处理 x 为 6 的情况。当 x 为 6 时，它应该递增为 7，然后在下一个循环迭代中变为 1。
//背完手敲



//输入一组勾股数，用分数格式输出其较小锐角的正弦值。（要求约分。）
//#include<bits/stdc++.h>    //万能库，本题要用的库有<algorithm>和<numeric>
//using namespace std;
#include<algorithm>
#include<numeric>

//洛谷编译器识别不出来：手写gcd函数
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main1()
{
    int a[4];    //数组用来存储三角形三条边    
    for (int i=0;i<3;i++)    //因为是勾股数 一共只有三个数 所以循环三次来读入三个数 
    {
        cin>>a[i];    //把数都存在一个数组 
    }
    sort(a,a+3);    //把三个数从小到大排列 此时a[0]就是最小直角边 a[2]为斜边
    cout<<a[0]/gcd(a[0],a[2])<<'/'<<a[2]/gcd(a[0],a[2]);      //因为要约分 所以用gcd(a[0],a[2]）取a[0]与a[2]的最大公约数
                                                                                              // a[0]/最大公约数的值与a[2]/最大公约数的比值即是约分后的结果 
    return 0;
}