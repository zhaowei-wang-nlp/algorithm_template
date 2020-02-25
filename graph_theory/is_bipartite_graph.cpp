#include<iostream>
#include<cstring>
using namespace std;
const int N = 200010;
int h[N], e[N], ne[N], idx, color[N];//无向图的边数组要开两倍
int n, m;
void add(int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx; idx ++;
}
bool dfs(int x, int c)
{
    color[x] = c;
    for(int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!color[j])//如果相邻点没有被染色，那么久递归染相反的颜色
        {
            if(!dfs(j, 3-c))
                return false; 
        }
        else if(color[j] == color[x]) return false;//如果相邻点染色了且颜色相同
    }
    return true;
}
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    while(m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    bool flag = true;
    for(int i = 1; i <= n; i ++)
    {
        if(!color[i])
        {
            if(!dfs(i, 1))//如果当前点没有被染色那么就dfs进行染色
            {
                flag = false;
                break;
            }
        }
    }
    if(flag)
        printf("Yes");
    else
        printf("No");
    return 0;
}