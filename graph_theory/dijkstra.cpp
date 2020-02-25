#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510;
int g[N][N], m, n;
int dist[N];
bool st[N];
//朴素版地杰斯特拉, 用在稠密图中
int main()
{
    memset(g, 0x3f, sizeof g);
    for(int i = 0; i < n; i ++)
        g[i][i] = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);//这里读边的时候可以有重边，所以要取最小值
    }

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 1; i <= n; i ++)
    {
        int t = -1;
        for(int j = 1; j <= n; j ++)//每一步找一个dist最小的点
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;//标记当前点被访问过了
        for(int j = 1; j <= n; j ++)//更新其他点的dist数组
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    if(dist[n] == 0x3f3f3f3f) printf("-1");
    else printf("%d", dist[n]);
}