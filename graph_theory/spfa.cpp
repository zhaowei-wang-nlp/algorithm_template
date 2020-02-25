#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;
int dist[N], n, m;
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx; idx ++;
}
int main()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    queue<int> q;
    q.push(1);
    st[1] = true;
    while(q.size())//和bellman_ford算法不同的是
                   //只有dist[i]被松弛操作变小的时候才去看点i相邻点是否可以变小
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    q.push(j); 
                    st[j] = true;
                }
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) printf("impossible");
    else printf("%d", dist[n]);
    return 0;
}
