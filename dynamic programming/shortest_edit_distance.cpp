#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
char a[N], b[N];
int f[N][N];
int main()
{
    int n, m;
    cin >> n >> a + 1 >> m >> b + 1;
    for(int i = 1; i <= n; i ++)//这个地方要对一个字符串为空的情况进行初始化
        f[i][0] = i;
    for(int i = 1; i <= m; i ++)
        f[0][i] = i;
        
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            if(a[i] == b[j])
            {
                f[i][j] = f[i - 1][j - 1];//如果两个字符串末尾字符相同则不用修改
            } 
            else
                f[i][j] = min(f[i - 1][j] + 1, min(f[i][j - 1] + 1, f[i - 1][j - 1] + 1));//如果不同则需要进行修改
        }
    printf("%d", f[n][m]);
    return 0;
}