#include<iostream>
using namespace std;
const int N = 1010;
int f[N], mod = 1e9 + 7;
typedef long long LL;
//这个问题相当于一个完全背包问题
//状态表示f[i][j]表示使用不超过i的数字组成j的方法数
//本代码已经优化成了1维的状态数组
int main()
{
    int n;
    cin >> n;
    
    f[0] = 1;
    for(int i = 1; i <= n; i ++)
        for(int j = i; j <= n; j ++)
            f[j] = (f[j] + f[j - i]) % mod; 
    
    printf("%d", f[n]);
    return 0;
}