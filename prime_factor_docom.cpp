#include<iostream>
using namespace std;
void divide(int x)
{
    for(int i = 2; i <= x/i; i ++)
    {   //这个算法在i循环到合数质数之前，已经把合数的质因数分解从x中去除了，所以不会有输出合数因子的情况
        if(x % i == 0)//如果当前的数是因数的话
        {
            int cnt = 0;
            while(x % i == 0)
            {
                x = x/i;
                cnt ++;
            }
            printf("%d %d\n", i, cnt);
        }
    }
    if(x > 1) printf("%d %d\n", x, 1);
    printf("\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    while(n --)
    {
        int x;
        scanf("%d", &x);
        divide(x);
    }
    return 0;
}