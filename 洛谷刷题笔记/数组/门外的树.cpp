//由于马路上有一些区域要用来建地铁。这些区域用它们在数轴上的起始点和终止点表示。已知任一区域的起始点和终止点的坐标都是整数
//，区域之间可能有重合的部分。现在要把这些区域中的树（包括区域端点处的两棵树）移走。你的任务是计算将这些树都移走后，马路上还有多少棵树。
#include <iostream>
#include <vector>
using namespace std;
bool f[10001];
int l, m, sum;
int main(){
	cin >> l >> m;
	for(int u, v; m--; ){
		cin >> u >> v;
        for (int j=u; j<=v; ++j)
            f[j]=1;
	}
	for(int i=0; i<=l; i++)
        sum+=(!f[i]);
	cout << sum;
	return 0;
}