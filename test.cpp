#include<iostream>
#include<cstring>
using namespace std;
const int N = 110;
int h[N], ne[N], e[N], idx;
int v[N], w[N];
int n, m, root;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int * dfs(int u)
{
    static int f[N];
    memset(f, 0, sizeof f);
    
    if(v[u] > m) return f;
    
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int *a = dfs(e[i]);
        for(int j = m - v[u]; j >= 0; j --)
            for(int k = 0; k <= j; k ++)
                f[j] = max(f[j], f[j - k] + a[k]);
    }
    
    for(int j = m; j >= v[u]; j --) f[j] = f[j - v[u]] + w[u];
    for(int j = 0; j < v[u]; j ++) f[j] = 0;

    return f;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i ++)
    {
        int p;
        cin >> v[i] >> w[i] >> p;
        if(p == -1) root = i;
        else    add(p, i);
    }  

    int *f = dfs(root);

    cout << f[m];
    return 0;
}