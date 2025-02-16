//题目有点繁琐，多去看原题吧：https://www.luogu.com.cn/problem/P4414

#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int arr[3];
    char A,B,C;
    cin>>arr[0]>>arr[1]>>arr[2];
    cin>>A>>B>>C;
    sort(arr,arr+3);
    cout<<arr[A-'A']<<" "<<arr[B-'A']<<" "<<arr[C-'A'];//我靠这里真是太妙了
}
//代码简短但是很妙，背完去手敲


//ISBN 号码///////ex //#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string isbn;
    cin >> isbn; // 读取输入的 ISBN 号码

    int sum = 0;
    // 计算前9位数字的加权和
    //for (int i = 0; i < 9; i++) 
    //   sum += (isbn[i] - '0') * (i + 1);//这里比较巧妙，减去‘0’就是转换成数字,记住了哈c
    //上面是错的，因为ISBN号码中包含分隔符-，但你在计算校验和时直接遍历前9个字符，错误地将这些分隔符当作数字处理。
    int count = 0;
    // 遍历整个字符串，提取前9个数字字符进行计算
    for (int i = 0; i < isbn.size() && count < 9; i++) {
        if (isdigit(isbn[i])) {
            count++;
            sum += (isbn[i] - '0') * count; // 正确累加加权和
        }
    }
    // 计算校验和
    int remainder = sum % 11;
    char checkDigit = (remainder == 10) ? 'X' : (char)(remainder + '0');//双目运算符

    // 检查校验码是否正确
    if (isbn.back()==checkDigit) 
        cout << "Right" << endl;
    else 
    {
        // 如果校验码不正确，输出正确的 ISBN 号码
        isbn.back() = checkDigit;
        cout << isbn << endl;
    }

    return 0;
}
/*在 C++ 中，字符实际上是以整数形式存储的，通常是 ASCII 值。字符 ‘0’ 的 ASCII 值是 48，字符 ‘1’ 的 ASCII 值是 49，以此类推。
所以，如果你有一个字符 ‘3’，执行 ‘3’ - ‘0’ 的操作将得到整数 3。单引号用于表示单个字符； 双引号用于表示字符串字面量*/
//'5' - '0' 相当于 53 - 48，结果是 5（整数）。
//整数 5 加上字符 '0' 的 ASCII 码（48），结果是 53，对应字符 '5'。
/*也是报错了：未正确处理分隔符：ISBN号码中包含分隔符-，但你在计算校验和时直接遍历前9个字符，错误地将这些分隔符当作数字处理。

校验码转换错误：将余数转换为字符时，错误地使用减法而非加法，导致校验码字符不正确。*/

