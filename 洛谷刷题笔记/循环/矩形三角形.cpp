//输入 n；打印矩形，直角三角形（直角在右边）
//两个循环 一个行数一个列数，0用iomanip
#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int n;
    cin >> n;

    int num = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << setw(2)<<setfill('0')<<num++;
        }
        cout <<endl;
    }
    
    cout <<endl;

    num = 1; //记得重赋值
    for (int i = 1; i <= n; i++){

        for(int j = 1; j <= n - i ; j++) cout << "  ";

        for(int k = 1; k <= i; k++) {
            cout<<setw(2)<<setfill('0')<<num++;
        }

        cout<<endl;
    }
    return 0;
}

//爽