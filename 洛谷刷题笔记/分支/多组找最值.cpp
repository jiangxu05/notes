/*但是津津如果一天上课超过八个小时就会不高兴，而且上得越久就会越不高兴。假设津津不会因为其它事不高兴，
并且她的不高兴不会持续到第二天。请你帮忙检查一下津津下周的日程安排，看看下周她会不会不高兴；如果会的话，哪天最不高兴。
输入包括 7 行数据，分别表示周一到周日的日程安排。每行包括两个小于 10 的非负整数，
用空格隔开，分别表示津津在学校上课的时间和妈妈安排她上课的时间。*/
#include<iostream>

using namespace std;  
int main (){
    int a,b,s,max=0,i,day=0;  //a,b是津津（以下简称JJ）每天上课时间，s意为sum是上课时间之和 
    for (i=1;i<8;i++)   // i为循环变量，初始值为1，因为周一是第一天，所以i=1，循环条件为i<8，一周有7天，
      {
        cin>>a>>b;    //输入a,b ，一定要注意这俩数据实时更新，要放在for循环里
        s=a+b;   //计算一天的上课时间 
        if ((s>max)&&(s>8)) max=s,day=i;  //在超过8小时且比之前几天都大的s时，将s赋给最大值，并记录下JJ的这天 
      }
    cout<<day; //由于day初值是0，所以如果JJ一周都开心就输出0 
    return 0;             
}
//把思路记住，然后手敲一遍AC