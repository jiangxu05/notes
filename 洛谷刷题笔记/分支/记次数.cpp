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