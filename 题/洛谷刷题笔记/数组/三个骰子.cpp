//在那里她买了三个骰子。这三个不同的骰子的面数分别为 s1，s2,s3
//每个面（上的数字）出现的概率均等。贝茜希望找出在所有“三个面上的数字的和”中，哪个和的值出现的概率最大。
//现在给出每个骰子的面数，需要求出哪个所有“三个面上的数字的和”出现得最频繁。如果有很多个和出现的概率相同，那么只需要输出最小的那个。
//我的思路 s 分别展开 边求和边存次数 找出最大的 次数最多的 值
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    //下表为几就是几
    vector <int> jicishu = {0};

            vector <int> diyizushuju = {0};
            vector <int> dierzushuju = {0};
            vector <int> disanzushuju = {0};

            //展开数据
            for (int i = 1; i <= s1; i++) diyizushuju.push_back(i);
            for (int i = 1; i <= s2; i++) dierzushuju.push_back(i);
            for (int i = 1; i <= s3; i++) disanzushuju.push_back(i);
    //求和记次数
    for (int i = 0; i < s1; i++){
        for (int j = 0; j < s2; j++){
            for (int k = 0; k < s3; k++){
                jicishu[diyizushuju[i] + dierzushuju[j] + disanzushuju[k]]++;
            }
        }
    }
    //如何找出次数最多的数字的下标呢？？，，不会了




}

//解析
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    // 初始化计数数组，大小为 s1 + s2 + s3 + 1
    vector<int> jicishu(s1 + s2 + s3 + 1, 0);
    //我们希望数组的下标直接表示和的值。例如，jicishu[3] 表示和为3的次数，jicishu[4] 表示和为4的次数，依此类推。
    //由于和的最小值是3，最大值是 s1 + s2 + s3，所以数组需要能够覆盖从3到 s1 + s2 + s3 的所有值。
    //(s1 + s2 + s3) - 3 + 1 = s1 + s2 + s3 - 2;然后再加上0，1，2，三个；

    // 遍历所有可能的组合
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                jicishu[i + j + k]++;
                //妈的，一定要模拟一下，别把ijk初始值写成0；
            }
        }
    }

    // 找出出现次数最多的和
    int max_count = 0;
    int result = 0;
    for (int i = 3; i <= s1 + s2 + s3; i++) {  // 最小的和是3，最大是s1+s2+s3
        if (jicishu[i] > max_count) {
            max_count = jicishu[i];
            result = i;
        }
    }

    // 输出结果
    cout << result << endl;

    return 0;
}
