#include<iostream>
using namespace std;
const int N = 1000010;
int q[N], hh = 0, tt = -1;
int a[N];
int main()
{
    int m, k;
    scanf("%d%d", &m, &k);
    for(int i = 0; i < m; i ++)
    {
        scanf("%d", &a[i]);
    }
    
    for(int i = 0; i < m; i ++)
    {
        if(hh <= tt && (i - q[hh] + 1) > k) hh ++; //判断第一个值是不是已经过期了
        while(hh <= tt && a[q[tt]] >= a[i]) tt --;
        q[++ tt] = i;
        if(i >= k - 1) printf("%d ", a[q[hh]]);
    }
    printf("\n");
    hh = 0, tt = -1;//算最大值之前要清空队列
    for(int i = 0; i < m; i ++)
    {
        if(hh <= tt && (i - q[hh] + 1) > k) hh ++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt --;
        q[++ tt] = i;
        if(i >= k - 1) printf("%d ", a[q[hh]]);
    }
}