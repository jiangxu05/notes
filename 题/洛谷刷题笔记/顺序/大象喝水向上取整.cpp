#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int h,r;
    cin >> h >> r;
    double v = 3.14*r*r*h;
    int n = ceil(20000.0/v);
    return 0;
}
//这题从上学迟到学到了ceil函数的使用，但是要注意20000.0/v，不能写成20000/v，否则会出现整数除法的问题，导致结果不准确。