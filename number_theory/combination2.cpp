#include<iostream>
using namespace std;
const int N = 100010, mod = 1e9 + 7;
int factor[N], infactor[N];
typedef long long LL;
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
int main()
{
    int n;
    cin >> n;
    factor[0] = 1;
    infactor[0] = 1;
    for(int i = 1; i <= N; i ++)//原题目中a的范围是0-2000，所以应该算到数组中第2001个数字，而不是2000个数字
    {
        factor[i] = (LL)factor[i - 1] * i % mod;
        infactor[i] = fast_pow(factor[i], mod - 2);
    }
    while(n --)
    {
        int a, b;
        cin >> a >> b;
        printf("%d\n", (LL)factor[a] * infactor[b] % mod * infactor[a-b] % mod);
    }
    return 0;
}