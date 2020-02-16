#include<iostream>
#include<cstring>
using namespace std;
const int N = 200003, null = 0x3f3f3f3f;
int h[N];
int find(int x)
{
    int k = (x % N + N) % N;
    while(h[k] != null && h[k] != x)
    {
        k ++;
        if(k == N) k = 0;//k大于N的时候要置为0
    }
    return k;
}
int main()
{
    memset(h, 0x3f, sizeof h);//要将所有的整数设置为0x3f3f3f3f，表示该位置为空(改题的数据范围为10e-9-10e9)
    int n, x;
    char c;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        scanf(" %c%d", &c, &x);
        if(c == 'I')
        {
            int k = find(x);
            h[k] = x;
        }
        else
            if(h[find(x)] == x)
                printf("Yes\n");
            else
                printf("No\n");
    }
    return 0;
}