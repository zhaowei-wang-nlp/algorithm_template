#include<iostream>
using namespace std;
const int N = 100010;
int q[N], b[N];
void insert(int l, int r, int c)
{
    b[l] += c;
    b[r+1] -= c;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &q[i]);
        insert(i, i, q[i]);
    }
    int l, r, c;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    for(int i=1;i<=n;i++)
    {
        q[i] = q[i-1] + b[i];
        printf("%d ", q[i]);
    }
    return 0;
}