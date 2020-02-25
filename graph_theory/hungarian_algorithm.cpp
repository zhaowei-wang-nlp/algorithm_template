#include<iostream>
#include<cstring>
using namespace std;
const int N = 510, M = 100010;
int h[N], e[M], ne[M], idx, match[N], n1, n2, m;
bool st[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx; idx ++;
}
bool find(int x)
{
    for(int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(match[j] == 0 || find(match[j]))//match[j] == 0 表示在图中得到一条新的交错路径
                                //find(match[j])表示扩展当前图中存在的交错路径，查看是否能得到一条增广路径
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n1, &n2, &m);
    while(m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    int res = 0;
    for(int i = 1; i <= n1; i ++)//每次循环多加一个a侧节点进来
    {
        memset(st, false, sizeof st);//所有b侧节点都标记为未访问过
        //如果图中有环，不做st标记会陷入死循环
        if(find(i)) res ++;//找a侧第i个点的匹配点
    }
    printf("%d", res);
    return 0;
}
