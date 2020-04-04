#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
char a[N], b[N];
int f[N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    cin >> a + 1 >> b + 1;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            if(a[i] == b[j])//如果两个字符相同，则最长长度加1
                f[i][j] = f[i - 1][j - 1] + 1;
            else//如果两个字符不相同，则两个字符串中选择一个去掉最后一个字符
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    printf("%d", f[n][m]);
    return 0;
}