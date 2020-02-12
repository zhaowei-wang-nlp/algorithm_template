#include<iostream>
using namespace std;
const int N = 10010, M = 100010;
char s[M], p[N];//字符串从1开始
int ne[N] = {1, 1};//要初始化ne[1],ne[0]是多少无所谓
int main()
{
    int m, n;
    scanf("%d %s", &n, p + 1);
    scanf("%d %s", &m, s + 1);
    
    for(int i = 2, j = 1; i <= n; i ++)
    {
        while(j != 1 && p[i] != p[j]) j = ne[j - 1];
        if(p[i] == p[j]) j ++;
        ne[i] = j;
    }
    
    for(int i = 1, j = 1; i <= m; i ++)
    {
        while(j != 1 && s[i] != p[j]) j = ne[j - 1];
        if(s[i] == p[j]) j ++;
        if(j == n + 1)
        {
            j = ne[j - 1]; //匹配完成的时候也要p右移，继续匹配
            printf("%d ", i - n);
        }
    }
    return 0;
}