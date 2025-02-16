#include<iostream>
using namespace std;
int main(){
    int H,n=0;
    int arr[10];
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    cin>>H;
    H+=30;
    for(int j=0;j<10;j++){
        if(H>=arr[j]){
            n++;
        }
    }
    cout<<n;
    return 0;
}
//有答案这样的：for(int i=0;i<10;i++)s+=!(H<height[i]);
//!：这是一个逻辑非运算符，它会反转布尔表达式的结果。如果H<height[i]为true（即H小于height[i]），则!(H<height[i])将为false。



/*P 老师需要去商店买 n 支铅笔作为小朋友们参加 NOIP 的礼物。
她发现商店一共有 3 种包装的铅笔，不同包装内的铅笔数量有可能不同，价格也有可能不同。为了公平起见，P 老师决定只买同一种包装的铅笔。
现在 P 老师想知道，在商店每种包装的数量都足够的情况下，要买够至少 n 支铅笔最少需要花费多少钱。*/

//本题让我没想到的点，也是破题点：
//如果n%a不等于0，我们需要购买的包装数就是n/a+1
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
   int n,n1,p1,n2,p2,n3,p3,a1,a2,a3,ans; //n=num,p=price,a=all,ans=answer
    cin>>n>>n1>>p1>>n2>>p2>>n3>>p3;
    if(n%n1!=0) a1=(n/n1+1)*p1;
    else a1=n/n1*p1;
    if(n%n2!=0) a2=(n/n2+1)*p2;
    else a2=n/n2*p2;
    if(n%n3!=0) a3=(n/n3+1)*p3;
    else a3=n/n3*p3;
    ans=min(a1,min(a2,a3));
    cout<<ans;
    return 0;
}
//ok，在脑海里面过一遍就手敲一遍