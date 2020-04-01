#include<iostream>
using namespace std;
const int N = 2010;
int vs[N], w[N];
int n, m;
int f[N];
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        scanf("%d%d", &vs[i], &w[i]);

    for(int i = 0; i < n; i ++)
        for(int j = m; j >= vs[i]; j --)
            f[j] = max(f[j - vs[i]] + w[i], f[j]);
    printf("%d", f[m]);
    return 0;
}