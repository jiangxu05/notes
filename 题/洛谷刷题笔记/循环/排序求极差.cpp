//P5724

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int num;
    vector<int>v1; //默认构造 无参构造
    for ( int i = 0; i < n; i++){
        
        cin >> num  ;
        v1.push_back(num);

    }
    sort(v1.begin(),v1.end());

cout << v1.back() - v1.front();
return 0;

}