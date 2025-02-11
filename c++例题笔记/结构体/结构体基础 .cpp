/*结构体定义和使用：
结构体是一种自定义的数据类型，可以包含多个不同类型的成员变量，这些成员变量可以是基本数据类型、数组、指针、引用、甚至是其他结构体。
结构体的定义格式如下：
struct 结构体名
{
    成员变量类型1 成员变量名1;
    成员变量类型2 成员变量名2;
    ...
    成员变量类型n 成员变量名n;
};
结构体的使用格式如下：
结构体名 变量名;
变量名.成员变量名 = 值;
结构体变量可以作为函数的参数和返回值，也可以定义结构体数组。
*/

#include <iostream>
#include <string>   //引入string头文件
using namespace std;

struct Student
{
    int id;         //学号
    string name;  //姓名
    int age;        //年龄
};

int main()
{
    Student stu;    //在c++中可以省略struct关键字
    stu.id = 1001;
    stu.name = "张三";
    stu.age = 18;
/*
也可以在定义结构体变量时直接初始化：
Student stu = {1001, "张三", 18};
*/
    cout << "学号：" << stu.id << endl;
    cout << "姓名：" << stu.name << endl;
    cout << "年龄：" << stu.age << endl;
    return 0;
}


/*
结构体数组
*/
#include <iostream>
#include <string>

using namespace std;

struct Student
{
    int id;
    string name;
    int age;
};

int main()
{
    Student stu[3] = {
        {1001, "张三", 18},
        {1002, "李四", 19},
        {1003, "王五", 20}
    };
//给结构体数组中的元素赋值：
// stu[0].id = 1006;//则stu[0]的id为1006
    for (int i = 0; i < 3; i++)
    {
        cout << "学号：" << stu[i].id << endl;
        cout << "姓名：" << stu[i].name << endl;
        cout << "年龄：" << stu[i].age << endl;
    }
    return 0;
} 


/*
结构体指针
*/
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
};

int main()
{
    //struct可省略
    Student stu = {1001, "张三", 18};
    Student *p = &stu;  //定义结构体指针p，指向结构体变量stu
    cout << "学号：" << p->id << endl;  //通过指针访问结构体成员变量
    cout << "姓名：" << p->name << endl;
    cout << "年龄：" << p->age << endl;
    return 0;
}