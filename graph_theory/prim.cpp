#include<iostream>
#include<cstring>
using namespace std;
const int N = 510, M = 200010;
int h[N], e[M], ne[M], idx, w[M];
int dist[N], n, m;
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    while(m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int res = 0;
    for(int i = 0; i < n; i ++)
    {
        int t = -1;
        for(int j = 1; j <= n; j ++)
        {
            if(!st[j]&& (t==-1||dist[j]<dist[t]))//只是dist数组存的是到已访问过点集合的最小值
                t = j;
        }
        if(dist[t]==0x3f3f3f3f)//如果找不到有边的点了，那么说明图不连通
        {
            printf("impossible");
            return 0;
        }
        res += dist[t];//先记录当前dist[t],再去更新dist矩阵
        st[t] = true;
        for(int j = h[t]; j != -1; j = ne[j])
        {
            int k = e[j];
            dist[k] = min(dist[k], w[j]);
        }
    }
    printf("%d", res);
    return 0;
}