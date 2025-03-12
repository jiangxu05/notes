//输入n，输出前n行的杨辉三角
//n = 6
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//1 5 10 10 5 1
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> yanghui(n);

    for(int i = 0; i < n; i++){
        yanghui[i].resize(i + 1);  // 每行的元素个数为 i+1
        yanghui[i][0] = yanghui[i][i] = 1;  // 每行的第一个和最后一个元素为1

        for(int j = 1; j < i; j++){
            yanghui[i][j] = yanghui[i-1][j-1] + yanghui[i-1][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << yanghui[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//仅输出
#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int val = 1;
        for(int j = 0; j <= i; j++){
            cout << val << " ";
            val = val * (i - j) / (j + 1);  // 计算下一个值
        }
        cout << endl;
    }

    return 0;
}

#include<iostream>
using namespace std;
long long a,b[100][100];
int main() {
    cin>>a;
    b[1][1]=1;
    for(int i=1;i<=a;i++){
    	for(int j=1;j<=i;j++){
    		b[i][j]+=b[i-1][j-1]+b[i-1][j];
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
}