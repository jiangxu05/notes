#include<iostream>
#include<string>

using namespace std;
  
int main(){
/*
张三 100 100 100
李四 90  50  100
王五 60 70 80
*/
int scores[3][3] = {
    {100, 100, 100},
    {90, 50, 100},
    {60, 70, 80}
    };                                       // 创建二维数组
string names[3] = {"张三", "李四", "王五"};    // 创建一维数组

for(int i = 0; i < 3; i++){
    int sum = 0;                             // 总和
    
    for(int j = 0; j < 3; j++){
        sum += scores[i][j];                 // 计算总和
        cout << scores[i][j] << " ";
    }
    cout << names[i] << "的总成绩是：" << sum << endl;
}
    return 0;
}   