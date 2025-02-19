#include<iostream>

#include<cmath>
using namespace std;

int main(){
    double s;
    cin >> s;
    double a1 = 2;
    double sum = 0.0 ;
    double p =  0.98 ;
    int c = 0 ;
    while (sum <= s){
        sum = a1*pow(p, c);
        ++c;
    }
    cout << c;
    return 0;
}