#include<iostream>
#include<vector>
using namespace std;
const int N = 5010;
bool st[N];
int primes[N], idx;
void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[idx ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size(); i ++)
    {
        t += a[i] * b;
        c.push_back(t%10);
        t /= 10;
    }
    while(t)
    {
        c.push_back(t%10);
        t /= 10;
    }
    return c;
}
int get(int n, int p)
{
    int res = 0;
    while(n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}
int main()
{
    int a, b;
    cin >> a >> b;
    get_primes(a);
    vector<int> res;
    res.push_back(1);
    for(int i = 0; i < idx; i ++)
    {
        int x = get(a, primes[i]);
        x -= get(b, primes[i]);
        x -= get(a - b, primes[i]);
        while(x)
        {
            res = mul(res, primes[i]);
            x --;
        }
    }
    for(int i = res.size() - 1; i >= 0; i --)
        printf("%d", res[i]);
    return 0;
}
