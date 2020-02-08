#include<iostream>
const int N = 100010;
int q[N];
int S[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &q[i]);
    }
    for(int i=1;i<=n;i++)
    {
        S[i] = S[i-1] + q[i-1];
    }
    int l, r;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", S[r] - S[l-1]);
    }
    return 0;
}