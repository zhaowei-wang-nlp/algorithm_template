#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//这个题是一个树形dp的题，由于树是有向树，所以要从根节点开始遍历，并且不用一个st数组存储哪个点遍历过了
//相反，如果一个树是无向树，则任意一个点都可能是跟节点，所以可以从任意一个点开始遍历，并且需要一个st数组存储哪个点遍历过了
const int N = 6010;
int h[N], ne[N], e[N], idx;
int n, cost[N], f[N][2], has_father[N];
//这个题使用dfs遍历树种所有节点，一边遍历一边动归
//状态标识f[i][0]标识以i为根的子树，不包含根节点的最大答案
//状态标识f[i][1]标识以i为根的子树，包含根节点的最大答案
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dfs(int a)
{
    f[a][1] = cost[a];
    for(int i = h[a]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[a][1] += f[j][0];
        f[a][0] += max(f[j][0], f[j][1]);
    }
}
int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for(int i = 1; i <= n; i ++)
        scanf("%d", &cost[i]);
    
    int a, b;
    for(int i = 0; i < n - 1; i ++)
    {
        scanf("%d%d", &b, &a);
        add(a, b);
        has_father[b] = true;
    }
    
    int root = 1;
    while(has_father[root]) root ++;
     
    dfs(root);
    
    cout << max(f[root][0], f[root][1]);
    return 0;
}