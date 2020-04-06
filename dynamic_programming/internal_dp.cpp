#include<iostream>
#include<algorithm>
using namespace std;
const int N = 310;
int w[N], f[N][N], s[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> w[i];
    for(int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + w[i];
        
        
    for(int len = 2; len<= n; len++) // 枚举区间长度
        for(int i = 1; i + len - 1 <= n; i ++) // 枚举区间开始位置
        {
            int l = i, r = i + len - 1;
            f[l][r] = 0x3f3f3f3f;
            for(int k = l; k < r; k ++)
            {
                f[l][r] = min(f[l][r], f[l][k] + f[k+1][r] + s[r] - s[l - 1]);
            }
        }

    printf("%d\n", f[1][n]);
    return 0;
}