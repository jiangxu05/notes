//1
#include<iostream>
using namespace std;
int main(){
    cout<<"夫学须静也，"<<endl<<"才须学也。"<<endl<<"非学无以广才，"<<endl<<"非志无以成学。"<<endl;
    return 0;
}

//2
//今天是周六，又到了可以休息的日子了，7天后又会是一个周六。请你帮忙计算下，n（n为整数，可以是正也可以为负）天后会是星期几呢？
//n可能是负数，表示n天前是星期几。


#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string  week[7]={"星期一","星期二","星期三","星期四","星期五","星期六","星期日"};
    int m = (5 + n) % 7;
    if(m<0){
        m+=7;
    }
    cout<<week[m]<<endl;
    return 0;
}
//你的代码逻辑已经接近正确，但在处理正数 n 时仍然存在问题。具体来说，(n-1)%7+6 的计算方式可能会导致索引超出数组范围，或者计算结果不正确。


//7
//输入多个字符串,以aaa结束,将每个字符串中的数字字符按输入顺序提取前2位构成一个整数，求每个字符串提取的整数之和。字符串中没有数字的，则提取的整数视为0；不足2位的按实际提取的整数计算。例如：“a1b2”形成整数12；”a3b”形成整数3。
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    int ans = 0;
    while(cin>>str){
        if(str=="aaa"){
            break;
        }
        int sum=0,count = 0;
        for(size_t i=0;i<str.size() ; i++){
            if(isdigit(str[i])){
                sum = sum*10 + (str[i] - '0');//漏了这步看了半天。。
                count++;
                if(count==2){   
                    break;
                }
            }
        }
        ans+=sum;
    }
    cout<<ans<<endl;
    return 0;
}


//6
//对于一份试卷，如果考试结果的及格率不低于75%、良好率不低于25%，则认为该试卷的考题是合适的。这里约定及格成绩是指不低于试卷总分的60%的成绩，良好成绩是指不低于试卷总分的80%的成绩。给你试卷总分m和考生人数n，再告诉你n个考生的成绩，请判断该试卷是否合适并计算及格率和良好率。
//第一行输入试卷总分m和考生人数n第二行输入n个整数，表示考生成绩，第i个考生的成绩为ai
//在一行上输出评价、及格率和良好率，数据之间以一个空格间隔。若考题合适评价为Yes，否则评价为No。及格率和良好率都以百分比形式表示，且保留1位小数。
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<int> score(n);
    for(int i=0;i<n;i++){
        cin>>score[i];
    }
    int jige = 0,youxiu = 0;
    for(int i=0;i < n; i++){
        if (score[i] >= m * 0.8){
            youxiu++;
        }
        if(score[i] >= m * 0.6){ //这里之前写了else if，导致只有一个if成立，草改了半天。
            jige++;
        }
    }
    double jigelv = jige * 100.0 / n;
    double youxiulv = youxiu * 100.0 / n;
    cout<<(jigelv >= 75 && youxiulv >= 25 ? "Yes" : "No")<<" "<<fixed<<setprecision(1)<<jigelv<<"% "<<fixed<<setprecision(1)<<youxiulv<<"%"<<endl;
    return 0;
}

//3
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double danjia[10];
    int shuliang[10];
    for( int i = 0; i < 10 ; i ++) cin>>danjia[i];
    for( int i = 0; i < 10 ; i ++) cin>>shuliang[i];
    double dixiao;
    cin >> dixiao;
    double sum = 0.0;
    for(int i = 0; i < 10 ; i++) sum += danjia[i] * shuliang[i];
    double ans = sum - dixiao;
    if(ans < 0) ans = 0.000;
    cout<<fixed<<setprecision(3)<<ans<<endl;
    return 0;
}


//5
//小X很喜欢盲盒，尤其喜欢拆到隐藏款。蛋仔派对推出一款盲盒，包括1个超级隐藏款、2个隐藏款、4个异色款和8个常规款。小X购买了n个盲盒，如果小X开出了超级隐藏款和2个隐藏款，心情为“ha ha ha ha ha ha”，如果只开出了超级隐藏款和其中一个隐藏款，心情为“ha ha ha ha ha”如果只开出了超级隐藏款，心情为“ha ha ha ha”，如果没开出超级隐藏款但开出了任一个隐藏款，心情为“ha ha ha”，如果超级隐藏款和隐藏款都没有开出，但开出了任一异色款，心情为“ha ha”，如果只开出了常规款，心情为“he he”。
//本题给出小X开出的所有盲盒信息，请你判断下小X的心情。
//输入第一行给出一个整数n(1<=n<=100)，为小X购买的盲盒个数。
//接下来一行给出n个整数，分别为开出的盲盒款式，其中0代表超级隐藏款，1和2为隐藏款，3-6为异色款，7-14为常规款。
//输出为两行，第一行输出4个整数，分别为小X开出的超级隐藏款、隐藏款、异色款和常规款的个数。
//第二行输出小X的心情，格式为：
//如果超级隐藏款和2个隐藏款都开出，输出 ha ha ha ha ha ha；
//如果开出了超级隐藏款和其中一个隐藏款，输出 ha ha ha ha ha;
//如果开出了超级隐藏款但没有开出隐藏款，输出 ha ha ha ha；
//如果没开出超级隐藏款但开出了至少一个隐藏款，输出 ha ha ha；
//如果超级隐藏款和隐藏款都没有开出，但开出了任一异色款，输出 ha ha；
//如果只开出了常规款，输出 he he.
//其它情况不输出。
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> box(n);
    vector<int> cnt(4); // 分别存储超级隐藏款、隐藏款、异色款、常规款的数量

    // 统计各类盲盒的数量
    for (int i = 0; i < n; i++) {
        cin >> box[i];
        if (box[i] == 0) {
            cnt[0]++;
        } else if (box[i] == 1 || box[i] == 2) {
            cnt[1]++;
        } else if (box[i] >= 3 && box[i] <= 6) {
            cnt[2]++;
        } else {
            cnt[3]++;
        }
    }

    // 输出各类盲盒的数量
    cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << " " << cnt[3] << endl;

    // 判断心情
    string mood;
    if (cnt[0] >= 1 && cnt[1] >= 2) {
        mood = "ha ha ha ha ha ha";
    } else if (cnt[0] >= 1 && cnt[1] >= 1) {
        mood = "ha ha ha ha ha";
    } else if (cnt[0] >= 1) {
        mood = "ha ha ha ha";
    } else if (cnt[1] >= 1) {
        mood = "ha ha ha";
    } else if (cnt[2] >= 1) {
        mood = "ha ha";
    } else {
        mood = "he he";
    }

    // 输出心情
    cout << mood << endl;

    return 0;
}