// 第一行 n 个评委，第二行 n 个分; 输出两位小数，去最大值最小值；
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    double sum = 0.0;
    double arr[1001];

    for(int i = 0; i < n; i++){
        cin >> arr[i];

    }
    sort(arr,arr+n);

    int j = 1;
    while (j != n-1){
        sum += arr[j];
        j++;
    }
    

    cout << fixed << setprecision(2)<< sum / (n - 2) << endl;
    
    return 0;
}



//if 里面的return，while (1)无限循环 P4956



#include<iostream>

using namespace std;

int main(){
    int n,x , k = 1;

    cin >> n;
    while(1){ //1无限循环
    for(x = 100; x > 0; x--){
        
        if((7*x + 21*k)*52 == n) {
            cout << x<<endl<<k;
            return 0;    //别漏了啊
        }
    }
    k++; //这个放在for循环外面
    }
    
    return 0;
}