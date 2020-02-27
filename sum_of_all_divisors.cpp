#include<iostream>
#include<unordered_map>
using namespace std;
const int mod = 1e9+7;
int main()
{
    int n;
    unordered_map<int, int> primes;
    scanf("%d", &n);
    while(n --)
    {
        int x;
        scanf("%d", &x);
        for(int i = 2; i <= x/i; i ++)
            while(x%i==0)
            {
                primes[i] ++;
                x /= i;
            }
        if(x > 1) primes[x] ++;
    }
    long long res = 1;
    for(auto p: primes)
    {
        long long temp = 1;
        for(int i = 0; i < p.second; i ++)
        {
            temp = ((temp * p.first) + 1) % mod;
        }
        res = (res * temp) % mod;
    }
    printf("%d", res);
}