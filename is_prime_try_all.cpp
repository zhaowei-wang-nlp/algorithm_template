#include<iostream>
using namespace std;
bool is_prime(int x)
{
    if(x<2) return false;//小于2的数字都不是质数
    for(int i = 2; i <= x/i; i ++)//此处i从2开始，不是1或者0
    {
        if(x%i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        if(is_prime(x))
            printf("Yes\n");
        else printf("No\n");
        
    }
    return 0;
}