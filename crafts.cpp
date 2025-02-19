#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

bool book [100000001];

void isprime(int b){
    memset(book,true,sizeof(book));
    book[1] = false;

    int n =sqrt(b);
    for(int i = 2 ; i <= n ; i++){
        if (book[i]){
            for(int j = 2; j <= b / i ; j++){
                book[ i * j ] = false;
            }
        }
    }
    
}

bool ishuiwen(int num){
    int temp = num , ans = 0;
    while(temp != 0){
        ans = ans * 10 + temp % 10;
        temp /= 10;
    }
    if (ans == num) 
    return true;
    else
    return false;
}

int main(){
    int a,b;
    cin >> a >> b;
    if (b >= 10000000) // 如果 b 超过 10000000，则限制为 9999999
        b = 9999999;

    isprime(b);
    if (a > b) // 如果 a > b，直接结束
        return 0;
    
    
    if (a %2 == 0) a++;
    for (int i = a; i <= b; i += 2){
        if (book [i] && ishuiwen(i)) cout << i <<endl;
    }
    return 0;
}