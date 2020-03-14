#include<iostream>
using namespace std;
typedef long long LL;
int fast_pow(int a, int p)
{
    int b = p - 2;
    LL ans = 1;
    while(b)
    {
        if(b&1) ans = ans * a % p;
        a = a * (LL) a % p;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a, p;
        scanf("%d%d", &a, &p);
        if(a % p == 0)
            printf("impossible\n");
        else
            printf("%d\n", fast_pow(a, p));
    }
    return 0;
}