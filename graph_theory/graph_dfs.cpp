#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010;
int h[N], e[N * 2], ne[N * 2], idx, n;
bool st[N];//st标记每个点是否被访问过
void add(int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx; idx ++;
}

void dfs(int a)
{
    st[a] = true;//标记当前点被访问过
    for(int i = h[a]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])//和一般dfs不一样，树和图遍历所有相邻点的时候，只有相邻点未被访问过的时候才递归dfs
        //而八皇后问题或者类似的问题对应的是一颗树，我们的递归搜索规则保证了不会对一个点访问多次
        {
            dfs(j);
        }
    }
}
int main()
{   
    memset(h, -1, sizeof h);
    int a, b;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i ++)
    {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);//无向图要加两条边
    }
    dfs(1);
    return 0;
}