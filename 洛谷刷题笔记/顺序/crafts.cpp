#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
    double a,b,c;
    cin>>a>>b>>c;
    double p = (a+b+c)/2;
    double s = sqrt(p*(p-a)*(p-b)*(p-c));
    cout<<fixed<<setprecision(1)<<s<<endl;
    return 0;

}