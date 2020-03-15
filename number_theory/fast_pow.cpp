#include<iostream>
using namespace std;
typedef long long LL;
int fast_pow(int a, int b, int p)
{
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
    while(n --)
    {
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        printf("%d\n", fast_pow(a, b, p));
    }
    return 0;
}