#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N = 2010, M = 10010;
int h[N], e[M], ne[M], idx, w[M];
int dist[N], cnt[N], st[N], n, m;//dist不用初始化
void add(int a, int b, int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx; idx ++;
}
//这是用spfa判断图中有没有负环的代码
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    queue<int> q;
    for(int i = 1; i <= n; i ++)
    {
        q.push(i);//最开始要把所有的点加进来，防止图不连通
        st[i] = true;
    }
    while(q.size())
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
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n)//如果图中有负环的话，那么到某些点的路径的最小值就是负无穷，
                               //同时路径会被更新无数次,cnt记录当前路径的长度
                {
                    printf("Yes");
                    return 0;
                }
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    printf("No");
    return 0;
}