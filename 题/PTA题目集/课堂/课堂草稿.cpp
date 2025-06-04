// 编写类Point，包含以下成员函数:

// setPoint：设置点的x和y坐标
// getX：获取点的x坐标
// getY：获取点的y坐标
// print：打印点的信息
// 裁判测试程序样例：
// #include<iostream> 
// using namespace std;     

// // 请将答案填写在这里

// int main() {
//     int x, y;
//     cin >> x >> y;
//     Point p;
//     p.setPoint(x, y); // 设置点的坐标
//     cout << "x: " << p.getX() << endl; // 输出x坐标
//     cout << "y: " << p.getY() << endl; // 输出y坐标
//     p.print(); // 打印点的信息
//     return 0;
// }
// 输入样例：
// 输入某个点的x，y坐标。例如：

// 2 3
// 输出样例：
// 在这里给出相应的输出。例如：

// x: 2
// y: 3

// (2, 3)

class Point{
    private:
        int x,y;
    public:
        void setPoint(int newX,int newY){
            x = newX;
            y = newY;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
        void print(){
            cout<<"("<<x<<", "<<y<<")"<<endl;
        }
};

//this是一个指向当前对象的指针。当成员函数的参数名与类的成员变量名相同时，使用this可以明确区分两者。具体到这段代码：
//等效：void setPoint(int newX,int newY){
//x = newX;
//y = newY;


//2
// 编写类Circle，包含以下成员函数：

// setCircle: 设置圆的x, y坐标和半径
// getArea: 获取圆的面积，π取3.14
// print：打印圆的信息
// 裁判测试程序样例：
// #include<iostream> 
// using namespace std;     

// // 请将答案填写在这里

// int main() {
//     double x, y, r;
//     cin >> x >> y >> r;
//     Circle p;
//     p.setCircle(x, y, r); // 设置圆的x, y坐标和半径
//     cout << "area: " << p.getArea() << endl; // 输出圆的面积
//     p.print(); // 打印圆的信息（使用cout，不要用printf）
//     return 0;
// }
// 输入样例：
// 输入圆的x，y坐标和半径。例如：

// 0.0 0.0 1.0
// 输出样例：
// 输出圆的面积和信息。例如：

// area: 3.14
// x: 0, y: 0, r: 1

class Circle{
    private:
        double x,y,r;
    public:
        void setCircle(double newX,double newY,double newR){
            x = newX;
            y = newY;
            r = newR;
        }
        double getArea(){
            return 3.14*r*r;
        }
        void print(){
            cout<<"x: "<<x<<", y: "<<y<<", r: "<<r<<endl;
        }
};

//3
// -3 你好，构造函数（带参数）
// 分数 10
// 作者 向训文
// 单位 惠州学院
// 编写Point类，使得下列程序正确运行：

// 裁判测试程序样例：
// #include<iostream> 
// using namespace std;

// // 请将答案填写在这里

// int main() {
//     int x, y;
//     cin >> x >> y;

//     Point p1(x, y); // 构造函数传入两个参数
//     cout << p1.getX() << " " << p1.getY() << endl;
//     return 0;
// }
// 输入样例：
// 输入x和y坐标。例如：

// 21 2
// 输出样例：
// 输出点的坐标。例如：

// 21 2

class Point{
    private:
        int x,y;
    public:
        Point(int newX,int newY){
            x = newX;
            y = newY;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
};


//4
// 编写Fraction 类，封装分数的基本功能。
// (1)实现函数重载。
// (2)实现各个成员函数、友元函数。
//  (3) 规范化分数，即分母为0时，将其分母置1

// 类的定义：
// class Fraction
// {
// public:
//     Fraction(); //缺省构造函数设置分子为0，分母为1
//     Fraction(int n); //只有1 个参数，设置分子为n，分母为1
//     Fraction(int n, int d); //设置分子为n，分母为d
//     void setValue(int n, int d); //设置分子和分母
//     int getNum(); //获取分子值
//     int getDen(); //获取分母值
//     double getDoubleValue(); //获取分数对应的小数值
//     Fraction add(const Fraction & f2);  //分数相加 
        
//     Fraction operator*(const Fraction &f2);  //分数相加 
        
         
//     void output(); //按分数形式显示最简分数,按真分数或带分数形式输出，不要有多余的空格 
        
//     friend ostream &operator<<(ostream &out, Fraction &f);//重载输出，分数形式显示最简分数,按真分数或带分数形式输出，不要有多余的空格 
//     friend istream &operator>>(istream &in, Fraction &f); //输入重载 
// private:
//     int num; //分子
//     int den; //分母
//     void normalize();//规范化 
//     int gcd();  //求最大公约数
// };
// 裁判测试程序样例：
// #include <iostream>
// using namespace std;
// class Fraction
// {
// public:
//     Fraction(); //缺省构造函数设置分子为0，分母为1
//     Fraction(int n); //只有1 个参数，设置分子为n，分母为1
//     Fraction(int n, int d); //设置分子为n，分母为d
//     void setValue(int n, int d); //设置分子和分母
//     int getNum(); //获取分子值
//     int getDen(); //获取分母值
//     double getDoubleValue(); //获取分数对应的小数值
//     Fraction add(const Fraction & f2);  //分数相加 
        
//     Fraction operator*(const Fraction &f2);  //分数相加 
        
         
//     void output(); //按分数形式显示最简分数,按真分数或带分数形式输出，不要有多余的空格 
        
//     friend ostream &operator<<(ostream &out, Fraction &f);//重载输出，分数形式显示最简分数,按真分数或带分数形式输出，不要有多余的空格 
//     friend istream &operator>>(istream &in, Fraction &f); //输入重载 
// private:
//     int num; //分子
//     int den; //分母
//     void normalize();//规范化 
//     int gcd();  //求最大公约数
// };
// int main()
// {
//     Fraction f1, f2(2), f3(-3,4);
//     int num,den;
//     //输入两个分数 
//     cin>>num>>den;
//     f1.setValue(num,den);
//     cin>>f2;

//     cout<<"Fraction f1 is ";
//     f1.output();
//     cout<<"its double value is: "<<f1.getDoubleValue()<<endl;


//     cout<<"Fraction f2 is ";
//     cout<<f2;
//     cout<<"its double value is: "<<f2.getDoubleValue()<<endl;

//     cout<<"f1+f2=";  
//     f1.add(f2).output();
//     f3=f1*f2;
//     cout<<"f1*f2=";
//     cout<<f3;
//     return 0;
// }

// /* 请在这里填写答案 */

// 输入样例：
// 6 4
// 4 6
// 输出样例：
// Fraction f1 is 1 1/2
// its double value is: 1.5
// Fraciont f2 is 2/3
// its double value is: 0.666667
// f1+f2=2 1/6
// f1*f2=1



#include <iostream>
using namespace std;

// 构造函数
Fraction::Fraction() : num(0), den(1) {}

Fraction::Fraction(int n) : num(n), den(1) {}

Fraction::Fraction(int n, int d) : num(n), den(d) { normalize(); }

// 设置分子和分母
void Fraction::setValue(int n, int d) {
    num = n;
    den = d;
    normalize();
}

// 获取分子值
int Fraction::getNum() { return num; }

// 获取分母值
int Fraction::getDen() { return den; }

// 获取分数对应的小数值
double Fraction::getDoubleValue() { return static_cast<double>(num) / den; }

// 计算最大公约数
int Fraction::gcd() {
    int a = abs(num);
    int b = abs(den);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 规范化分数
void Fraction::normalize() {
    if (den == 0) {
        den = 1;
    }
    if (den < 0) {
        num = -num;
        den = -den;
    }
    int common_divisor = gcd();
    if (common_divisor != 0) {
        num /= common_divisor;
        den /= common_divisor;
    }
}

// 分数相加
Fraction Fraction::add(const Fraction & f2) {
    int new_num = num * f2.den + f2.num * den;
    int new_den = den * f2.den;
    return Fraction(new_num, new_den);
}

// 分数相乘
Fraction Fraction::operator*(const Fraction &f2) {
    int new_num = num * f2.num;
    int new_den = den * f2.den;
    return Fraction(new_num, new_den);
}

// 输出分数
void Fraction::output() {
    if (den == 1) {
        cout << num;
    } else if (abs(num) > den) {
        int whole = num / den;
        int remainder = abs(num) % den;
        if (remainder == 0) {
            cout << whole;
        } else {
            cout << whole << " " << remainder << "/" << den;
        }
    } else {
        cout << num << "/" << den;
    }
}

// 重载输出运算符
ostream &operator<<(ostream &out, Fraction &f) {
    if (f.den == 1) {
        out << f.num;
    } else if (abs(f.num) > f.den) {
        int whole = f.num / f.den;
        int remainder = abs(f.num) % f.den;
        if (remainder == 0) {
            out << whole;
        } else {
            out << whole << " " << remainder << "/" << f.den;
        }
    } else {
        out << f.num << "/" << f.den;
    }
    return out;
}

// 重载输入运算符
istream &operator>>(istream &in, Fraction &f) {
    in >> f.num >> f.den;
    f.normalize();
    return in;
}
//5
// 设学生信息的结构体设计如下：

// struct Stu {
//     string username;  //用户名
//     int diff;   //进步总数
//     int total;  //解题总数
// };
// 解题进步排行榜中，按进步总数diff及解题总数toatal生成排行榜。要求先输入n个学生的信息；然后按diff降序排列；若diff相同，则按toatal降序排列；若diff和toatal都相同，则按用户名username升序排列。

// 要求实现一个比较函数cmp，该函数作为sort()函数的第三个参数。

// 函数接口定义：
// bool cmp(Stu s, Stu t);
// 其中 s 和 t 是用户传入的两个Stu类型的结构体参数。

// 裁判测试程序样例：
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// bool cmp(Stu s, Stu t);

// //输入整数n，再输入n个学生的信息，按要求排序后输出，处理到文件尾 
// int main() {
//     int n;
//     while(cin>>n) {
//         Stu a[n];
//         int i;
//         for(i=0; i<n; i++) cin>>a[i].username>>a[i].diff>>a[i].total;
//         sort(a, a+n, cmp);
//         for(i=0; i<n; i++) cout<<a[i].username<<" "<< a[i].diff<<" "<<a[i].total<<endl;
//     }
//     return 0;
// }
// // 输入样例：
// // 10
// // usx15131 21 124
// // usx15101 27 191
// // usx15107 24 154
// // usx15113 31 124
// // usx15117 27 191
// usx15118 21 124
// usx15119 22 117
// usx15121 43 214
// usx15128 21 124
// usx15136 27 199
// 输出样例：
// usx15121 43 214
// usx15113 31 124
// usx15136 27 199
// usx15101 27 191
// usx15117 27 191
// usx15107 24 154
// usx15119 22 117
// usx15118 21 124
// usx15128 21 124
// usx15131 21 124

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Stu{
    string username;
    int diff;
    int total;
};

bool cmp(Stu s,Stu t){
    if(s.diff!=t.diff){
        return s.diff>t.diff;
    }
    if(s.total!=t.total){
        return s.total>t.total;
    }
    return s.username<t.username;
}

int main(){
    int n;
    while(cin>>n){
        Stu a[n];
        for(int i=0;i<n;i++){
            cin>>a[i].username>>a[i].diff>>a[i].total;
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
            cout<<a[i].username<<" "<<a[i].diff<<" "<<a[i].total<<endl;
        }
    }
    return 0;
}




// 7-1 判断能否形成等差数列
// 分数 20
// 作者 yzx
// 单位 兰州交通大学
// 给你一个数字数组 arr 。

// 如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 等差数列 。

// 如果可以重新排列数组形成等差数列，请返回 true ，并输出公差；否则，返回 false 。

// 当返回false时，默认公差为0.

// 要求用函数进行判断，否则不得分。

// 输入格式:
// 第一行输入数组长度。

// 第二行输入数组元素。

// 样例解释：对数组重新排序得到 [1,3,5] 或者 [5,3,1] (升序即可)，任意相邻两项的差分别为 2 或 -2 ，可以形成等差数列。

// 输出格式:
// true,2。

// 输入样例:
// 在这里给出一组输入。例如：

// 3
// 3 5 1
// 输出样例:
// 在这里给出相应的输出。例如：

// true,2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 判断是否为等差数列
bool isArithmeticSequence(vector<int>& arr, int& d) {
    if (arr.size() <= 1) {
        d = 0;
        return true; // 单个元素默认是等差数列
    }
    sort(arr.begin(), arr.end()); // 排序
    d = arr[1] - arr[0]; // 计算公差
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - arr[i-1] != d) {
            return false; // 发现差值不等
        }
    }
    return true; // 所有差值相等
}

int main() {
    int n;
    cin >> n; // 输入数组长度
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // 输入数组元素
    }
    int d;
    if (isArithmeticSequence(arr, d)) {
        cout << "true," << d << endl; // 是等差数列
    } else {
        cout << "false,0" << endl; // 不是等差数列
    }
    return 0;
}




// 7-2 航点排序
// 分数 10
// 作者 铁菊红
// 单位 成都信息工程大学
// 无人机一条航线由多个航点组成，航点主要信息有航点编号、经度和维度, 其中航点编号取值范围为1~255。请编写程序，使用冒泡排序算法对编号无序的多个航点按航点编号递增排序，并重新设置航点编号，第一个航点编号为1，后续编号依次增1。优化算法，当数据有序时程序结束，输出排序总趟数，以及排序后设置航点前后的航点信息。

// 输入格式:
// 输入第一行给出一个正整数 n（1<=n<=10), 随后 n 行，每行给出一个航点的信息：编号 经度 维度。其中编号取值范围为 1~255,经度取值范围为-180°~180°，维度取值范围为-90°~90°。

// 输出格式:
// 排序趟数单独占一行。每个航点占一行，航点信息以空格隔开，经度和维度保留6位小数。


// 输入样例:
// 5
// 1 100.23 50.12
// 3 101.78 54.56
// 5 103.98 52.12
// 6 104.76 51.78
// 4 100.65 50.65
// 输出样例:
// Total sorting: 2
// Before:
// 1 100.230000 50.120000
// 3 101.780000 54.560000
// 4 100.650000 50.650000
// 5 103.980000 52.120000
// 6 104.760000 51.780000
// After:
// 1 100.230000 50.120000
// 2 101.780000 54.560000
// 3 100.650000 50.650000
// 4 103.980000 52.120000
// 5 104.760000 51.780000

 #include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Point {
    int id;
    double jingdu;
    double weidu;
};

// 冒泡排序实现
int bubbleSort(vector<Point>& arr) {
    int n = arr.size();
    int count = 0;
    bool swapped;
    
    for (int i = 0; i < n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].id > arr[j+1].id) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        count++;
        if (!swapped) break; // 提前终止
    }
    original=arr;
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<Point> a(n);
    vector<Point> original(n); // 备份原始数据
    
    // 读取输入并备份
    for (int i = 0; i < n; i++) {
        cin >> a[i].id >> a[i].jingdu >> a[i].weidu;
    }
    
    // 执行冒泡排序并获取趟数
    int times = bubbleSort(a);
    
    // 输出排序趟数
    cout << "Total sorting: " << times << endl;
    
    // 输出排序前的数据（原始顺序）
    cout << "Before:" << endl;
    for (auto &p : original) {
        cout << p.id << " " 
             << fixed << setprecision(6) << p.jingdu << " "
             << fixed << setprecision(6) << p.weidu << endl;
    }
    
    // 重新设置ID
    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
    }
    
    // 输出排序后的数据
    cout << "After:" << endl;
    for (auto &p : a) {
        cout << p.id << " "
             << fixed << setprecision(6) << p.jingdu << " "
             << fixed << setprecision(6) << p.weidu << endl;
    }
    
    return 0;
}