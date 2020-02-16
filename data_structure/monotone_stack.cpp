#include<iostream>
using namespace std;
const int M = 100010;
int stk[M] = {-1}, tt = 0;
int main()
{
    int m, x;
    scanf("%d", &m);
    for(int i = 0; i < m; i ++)
    {
        scanf("%d", &x);
        while(tt>0 && stk[tt] >= x) tt--;
        printf("%d ", stk[tt]);
        stk[++ tt] = x;
    }
    return 0;
}