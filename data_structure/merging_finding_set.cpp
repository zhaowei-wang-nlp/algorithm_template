#include<iostream>
using namespace std;
const int N = 100010, M = 100010;
int p[N];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)//这里题目中的下表是1-n,不是0到n-1
        p[i] = i;
    
    int a, b;
    char c;
    for(int i = 1; i <= m; i ++)
    {
        scanf(" %c%d%d", &c, &a, &b);
        if(c == 'M')
            p[find(a)] = find(b);//合并两个集合的代码只有一行
        else if(c == 'Q')
            if(find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
    }
    return 0;
}