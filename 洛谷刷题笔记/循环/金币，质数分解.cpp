/*国王将金币作为工资，发放给忠诚的骑士。第一天，骑士收到一枚金币；之后两天（第二天和第三天），每天收到两枚金币；
这种工资发放模式会一直这样延续下去：当连续 n 天每天收到 n 枚金币后，骑士会在之后的连续 n+1 天里，每天收到 n+1 枚金币。
请计算在前 k 天里，骑士一共获得了多少金币。*/

//变动的数据都提取出来好吧：
//  zqian 总共的钱
// k k天
// fqtian 每个前的倒数天

//终于自主半小时做出来一道题；；；！fuck
#include<iostream>

 using namespace std;

 int main(){
    int k;
    cin>>k;
    int zqian = 0;
    int fqtian = 1;
    
    int fqian =1;

    for(int i =1 ;i<=k;i++){
       
        fqtian--;
        zqian+=fqian;
        if(fqtian==0){
            fqian++;
            fqtian=fqian;
        }

    }
    cout <<zqian<<endl;
    return 0;
 }

//输入质数 n； 求最大的因数，从 2开始遍历，小于根号n，之前学的性质；
#include<iostream>
#include<cmath>

using namespace std;

int main (){

    int n;
    cin >> n;

    for(int i = 2 ; i < sqrt(n) ; i++){ //注意2也是质数
        if (n % i == 0) cout<< n / i;
    }

    return 0;
}

