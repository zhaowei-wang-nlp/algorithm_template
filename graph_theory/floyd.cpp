#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 210;
int d[N][N], n, m, l;
int main()
{
    scanf("%d%d%d", &n, &m, &l);
    memset(d, 0x3f, sizeof d);
    for(int i = 1; i <= n; i ++)
        d[i][i] = 0;
    for(int i = 0; i < m; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);//这里要取最小值，以此去掉自环和重边
    }
    for(int k = 1; k <= n; k ++)
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for(int i = 0; i < l; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(d[a][b] > 0x3f3f3f3f/2)//这里要用0x3f3f3f3f/2
            printf("impossible\n");
        else
            printf("%d\n", d[a][b]);
    }
    return 0;
}
