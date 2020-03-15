#include<iostream>
#include<unordered_map>
using namespace std;
const int tt =  1e9+7;
//计算n个数字乘积的约数个数
int main()
{
    int n;
    unordered_map<int, int> primes;
    scanf("%d", &n);
    while(n --)
    {
        int a;
        scanf("%d", &a);
        for(int i = 2; i <= a/i; i ++)
            while(a%i == 0)
            {
                primes[i] ++;
                a = a / i;
            }

        if(a > 1)
            primes[a] ++;
    }
    long long res = 1;
    for(auto p: primes)
        res = res * (p.second + 1) % tt;
    printf("%d", res);
    return 0;
}