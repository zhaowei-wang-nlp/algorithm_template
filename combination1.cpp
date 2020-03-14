#include<iostream>
using namespace std;
const int N = 2010;
const int mod = 1e9 + 7;
int c[N][N];
typedef long long LL;
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= 2000; i ++)//预处理所有的组合数
    {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++)
            c[i][j] = ((LL)c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
    while(n --)
    {
        int a, b;
        cin >> a >> b;
        printf("%d\n", c[a][b]);
    }
    return 0;
}