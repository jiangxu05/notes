//字符还能相加减啊！
#include <iostream>

using namespace std;

int main(){
    char s;
    cin >> s;

    char m = s -('a'-'A'); //m大写，s小写，这么算就行。ASCII码大小写差32.
    cout << m << endl;


    return 0;
}