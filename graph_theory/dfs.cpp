//八皇后问题
#include<iostream>
using namespace std;
const int N = 10;//此处棋盘大小n最大为9,但是注意字符串数组要多留一个'\0'
int n;
bool column[N], dg[2*N-1], udg[2*N-1];
char g[N][N];
void dfs(int d)
{
    if(d == n)
    {
        for(int i = 0; i < n; i ++)
        {
            puts(g[i]);
        }

        puts("");
        return;
    }
    for(int i = 0; i < n; i ++)
    {
        if(!column[i] && !dg[d-i+n-1] && !udg[d+i])
        {
            column[i] = dg[d-i+n-1] = udg[d+i] = true;
            g[d][i] = 'Q';
            dfs(d + 1);
            column[i] = dg[d-i+n-1] = udg[d+i] = false;
            g[d][i] = '.';
        }
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            g[i][j] = '.';
    dfs(0);
    return 0;
}
