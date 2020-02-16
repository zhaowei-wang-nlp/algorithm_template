#include<iostream>
using namespace std;
const int N = 100010, P = 131;//P是131或者13331
char str[N];
typedef unsigned long long ULL;
ULL p[N] = {1}, h[N];//P[0]要初始化为1
ULL get(int l, int r)
{
    return h[r] - h[l-1] * p[r-l+1];
}
int main()
{
    int n, m;
    scanf("%d%d%s", &n, &m, str+1);
    for(int i = 1; i <= n; i ++)
    {
        h[i] = h[i - 1] * P + str[i];//P大于ascii码的数量，直接把char当成int就行
        p[i] = p[i - 1] * P;
    }
    
    while(m --)
    {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if(get(l1,r1) == get(l2,r2))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}