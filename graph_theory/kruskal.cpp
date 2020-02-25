#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010, M = 200010;
struct Edge
{
    int w, a, b;
    bool operator<(const Edge &W) const
    {
        return w<W.w;
    }
} e[M];
int p[N], n, m;
int find(int x)
{
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        p[i] = i;
    for(int i = 0; i < m; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[i].a = a, e[i].b = b, e[i].w = c;
    }
    sort(e, e+m);
    int res = 0, cnt = 0;
    for(int i = 0; i < m; i ++)
    {
        int a = find(e[i].a);
        int b = find(e[i].b);
        if(a!=b)
        {
            p[a] = b;
            cnt ++; res += e[i].w;
        }
    }
    if(cnt<n-1) printf("impossible");
    else printf("%d", res);
    return 0;
}
