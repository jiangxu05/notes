/*
结构体嵌套
*/
#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

struct Student
{
    int id;
    string name;
    Date birthday;
};

int main()
{
    Student stu;
    stu.id = 1001;
    stu.name = "张三";
    stu.birthday.year = 2000;
    stu.birthday.month = 1;
    stu.birthday.day = 1;

    cout << "学号：" << stu.id << endl;
    cout << "姓名：" << stu.name << endl;
    cout << "生日：" << stu.birthday.year << "年" << stu.birthday.month << "月" << stu.birthday.day << "日" << endl;
    return 0;
}


/*
结构体做函数参数
*/
#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

struct Student
{
    int id;
    string name;
    Date birthday;
};

//值传递：
void printStudent(Student stu)
{
    cout << "学号：" << stu.id << endl;
    cout << "姓名：" << stu.name << endl;
    cout << "生日：" << stu.birthday.year << "年" << stu.birthday.month << "月" << stu.birthday.day << "日" << endl;
}

int main()
{
    Student stu;
    stu.id = 1001;
    stu.name = "张三";
    stu.birthday.year = 2000;
    stu.birthday.month = 1;
    stu.birthday.day = 1;
    printStudent(stu);
    return 0;
}                                       //输出为：
                                        //学号：1001
                                        //姓名：张三
                                        //生日：2000年1月1日

//地址传递：
void printStudent(Student *stu)
{
    cout << "学号：" << stu->id << endl;
    cout << "姓名：" << stu->name << endl;
    cout << "生日：" << stu->birthday.year << "年" << stu->birthday.month << "月" << stu->birthday.day << "日" << endl;
}

int main()
{
    Student stu;
    stu.id = 1001;
    stu.name = "张三";
    stu.birthday.year = 2000;
    stu.birthday.month = 1;
    stu.birthday.day = 1;
    printStudent(&stu);
    return 0;
}
                                        //输出为：
                                        //学号：1001
                                        //姓名：张三
                                        //生日：2000年1月1日 
//值传递和地址传递的区别：
//值传递：传递的是实参的副本，对形参的修改不会影响实参
//地址传递：传递的是实参的地址，对形参的修改会影响实参
//例如：如果在printStudent函数中修改stu的值，值传递不会影响实参，地址传递会影响实参 


/*
结构体const修饰
*/
#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

struct Student
{
    int id;
    string name;
    Date birthday;
};

void printStudent(const Student *stu)
{
    //stu->id = 1002;  //编译器报错，防止误修改
    cout << "学号：" << stu->id << endl;
    cout << "姓名：" << stu->name << endl;
    cout << "生日：" << stu->birthday.year << "年" << stu->birthday.month << "月" << stu->birthday.day << "日" << endl;
}

int main()
{
    Student stu = {1001, "张三", {2000, 1, 1}};//注意这种写法  
    printStudent(&stu);
    return 0;
}                                       //输出为：
                                        //学号：1001
                                        //姓名：张三
                                        //生日：2000年1月1日
//const修饰的作用：
//1.防止修改：如果在printStudent函数中修改stu的值，编译器会报错
//2.提高效率：如果不加const修饰，传递结构体时会复制一份结构体，加const修饰后，传递的是结构体的地址，提高了效率