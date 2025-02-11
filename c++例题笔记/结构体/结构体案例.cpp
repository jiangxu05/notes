/*
学校正在做毕设项目，每名老师带领5个学生，总共3名老师，需求如下：设计学生和老师的结构体，
其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员，
学生的结构体成员有姓名考试分数 ，
创建数组存放三名老师，通过函数给每个老师及所带的学生赋值，
最终打印出老师数据以及老师所带的学生数据。
*/

#include <iostream>
#include <string>
#include <ctime>            //引入时间头文件，下面用到了随机数
using namespace std;

struct student
{
    string name;
    int score;
};              //别忘了加分号

struct teacher
{
    string name;
    student stuArray[5];
};

void allospace (teacher tArray[], int len){
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++){
        tArray[i].name = "Teacher_";
        tArray[i].name += nameSeed[i];          //给老师赋值

        int random = rand() % 61 + 40;          //给学生赋值,随机数范围40-100

        for (int j = 0; j < 5; j++){
            tArray[i].stuArray[j].name = "Student_";
            tArray[i].stuArray[j].name += nameSeed[j];

            tArray[i].stuArray[j].score = random;
        }
    }
}

void printinfo(teacher tArray[], int len){
    for (int i = 0; i < len; i++){
        cout << "Teacher's name: " << tArray[i].name << endl;
        for (int j = 0; j < 5; j++){
            cout << "Student's name: " << tArray[i].stuArray[j].name << " Student's score: " << tArray[i].stuArray[j].score << endl;
        }
    }
}

int main1 (){
    srand((unsigned int)time(NULL));    //随机数种子

    struct teacher tArray[3];       //创建三名老师的数组

    int len =  sizeof(tArray) / sizeof(tArray[0]); //计算数组长度

    allospace(tArray, len);         //给老师和学生赋值

    printinfo(tArray, len);         //打印老师和学生信息

    return 0;
}


/*
设计一个英雄的结构体，成员包括英雄姓名，年龄，性别；
创造结构体数组，数组中存放5名英雄；
通过冒泡排序算法，将数组中的英雄按照年龄升序排序最终打印排序后的结果 
*/

#include <iostream>
#include <string>
using namespace std;

struct hero
{
    string name;
    int age;
    string sex;
};

void bubbleSort(struct hero heroArray[], int len){
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (heroArray[j].age > heroArray[j+1].age){
                struct hero temp = heroArray[j];
                heroArray[j] = heroArray[j+1];
                heroArray[j+1] = temp;
            }
        }
    }
}

void printhero(struct hero herostruct[], int len){
    for (int i = 0 ; i < len; i++){
        cout << "hero's name:" << herostruct[i].name << " hero's age:" << herostruct[i].age;
    }
}

int main(){
    struct hero heroArray[5] = {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"}
    };
    int len = sizeof(heroArray)/sizeof(heroArray[0]);
    bubbleSort(heroArray, len);
    return 0;
}
