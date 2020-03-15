#include<iostream>
using namespace std;
const LL N = 100010;
typedef long long LL;//这个题a,b的范围是1e18,所以所有的整数都用long long 存
LL fast_pow(LL a, LL k, LL mod)
{
    LL res = 1;
    while(k)
    {
        if(k&0x1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        k >>= 1;
    }
    return res;
}
LL C(LL a, LL b, LL p)
{
    if(b>a)
        return 0;
    LL res = 1;
    for(LL i = 0; i < b; i ++)
    {
        res = (LL) res * (a - i) % p;
        res = (LL) res * fast_pow(b - i, p - 2, p) % p;
    }
    return res;
}
LL lucas(LL a, LL b, LL p)
{
    if(a < p && b < p) return C(a, b, p);
    return (LL)C(a%p, b%p, p) * lucas(a/p, b/p, p) % p;
}
LL main()
{
    LL n;
    cin >> n;
    while(n --)
    {
        LL a, b, p;
        cin >> a >> b >> p;
        prLLf("%d\n", lucas(a, b, p));
    }
    return 0;
}