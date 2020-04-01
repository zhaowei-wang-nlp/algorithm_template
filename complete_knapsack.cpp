#include<iostream>
using namespace std;
const int N = 1010;
int v[N], w[N], f[N];
int n, m;
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        scanf("%d%d", &v[i], &w[i]);
    }
    for(int i = 0; i < n; i ++)
        for(int j = v[i]; j <= m; j ++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    printf("%d", f[m]);
    return 0;
}