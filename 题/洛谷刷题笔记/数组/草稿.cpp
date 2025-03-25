//福到了
//输出倒置的网格，如样例所示。但是，如果这个字正过来倒过去是一样的，就先输出bu yong dao le，然后再用输入指定的字符将其输出。
//输入样例 1：
//$ 9
// @  @@@@@
//@@@  @@@ 
// @   @ @ 
//@@@  @@@ 
//@@@ @@@@@
//@@@ @ @ @
//@@@ @@@@@
// @  @ @ @
// @  @@@@@
//输出样例 1：
//$$$$$  $ 
//$ $ $  $ 
//$$$$$ $$$
//$ $ $ $$$
//$$$$$ $$$
// $$$  $$$
// $ $   $ 
// $$$  $$$
//$$$$$  $ 

//运行超时的代码
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    char c;
    int n;
    cin >> c >> n;

    vector<vector<char>> dianzheng(n,vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; i < n; j++){
            cin >> dianzheng[i][j];
        }
    }

    bool duicheng = true;
    for(int i = 0; i < n && duicheng; i++){
        for(int j = 0; j < n && duicheng; j++){
            if(dianzheng[i][j] != dianzheng[n - 1-i][n-1-j]) duicheng = false;
        }
    }

    if(duicheng) cout << "bu yong dao le" <<endl;
        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(dianzheng[i][j] == '@') cout << c;
                else cout << " ";
        }
        cout << endl;
    }
    return 0;
}