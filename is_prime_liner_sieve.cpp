#include<iostream>
#include<vector>
using namespace std;
const int N = 1000010;
bool st[N];
int main()
{
    int n;
    vector<int> primes;
    scanf("%d", &n);
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i]) primes.push_back(i);
        for(int j = 0; primes[j] <= n/i; j ++)//从小到大枚举所有质数,直到当前primes[j]是i的最小质因子
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
    printf("%d", primes.size());
    return 0;
}