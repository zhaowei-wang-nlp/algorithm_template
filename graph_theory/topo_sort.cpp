#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 100010;
int h[N], e[N], ne[N], idx;
int count[N], n, m, top[N], ix;
void add(int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx; idx ++;
}
//这个算法和广搜很像, 但也可以用栈这种数据结构
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        count[b] ++;//统计每个点的入度
    }
    queue<int> q;
    for(int i = 1; i <= n; i ++)
        if(!count[i])//这里要将所有入度为0的点加入队列
        {
            q.push(i);
            top[ix] = i;
            ix ++;
        }
    while(q.size())
    {
        int tt = q.front();
        q.pop();
        for(int i = h[tt]; i != -1; i = ne[i])
        {
            int j = e[i];
            count[j] --;//每个相邻的点的入度建一
            if(!count[j])
            {
                q.push(j);
                top[ix] = j;
                ix ++;
            }
        }
    }
    if(ix!=n) printf("-1");
    else
        for(int i = 0; i < n; i ++)
            printf("%d ", top[i]);
    return 0;
}
