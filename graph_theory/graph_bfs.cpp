#include<iostream>
#include<cstring>
using namespace std;
#include<queue>
const int N = 100010;
int h[N], e[N], ne[N], idx, m, n;
bool st[N];
void add(int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx; idx ++;
}
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    queue<int> q;
    q.push(1);
    st[1] = true;
    while(q.size())
    {
        int tt = q.front();
        q.pop();
        for(int i = h[tt]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!st[j])//访问图的时候也要用一个st记录每个点是否访问过
            {
                st[j] = true;
                q.push(j);
            }
        }
    }
    return 0;
}