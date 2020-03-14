#include<iostream>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
int fast_pow(int a, int k)
{
    int res = 1;
    while(k)
    {
        if(k&1) res = (LL)res * a % mod;
        a = (LL) a * a % mod;
        k >>= 1;
    }
    return res;
}
int C(int a, int b)
{
    if(b > a) return 0;
    int res = 1;
    for(int i = 0; i < b; i ++)
    {
        res = (LL) res * (a - i) % mod;
        res = (LL) res * fast_pow((b - i), mod - 2) % mod;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    int x = (LL)C(2*n , n) * fast_pow(n + 1, mod - 2) % mod;//除以n+1要乘上n+1的逆元
    printf("%d", x);
    return 0;
}