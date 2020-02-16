#include<iostream>
#include<cstring>
using namespace std;
const int N = 100003;
int h[N], e[N], ne[N], idx;//链表的head和index要初始化
void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx;
    idx ++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i])
        if(e[i] == x) return true;
    return false;
}
int main()
{
    int n, x;
    char c;
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        scanf(" %c%d", &c, &x);
        if(c == 'I')
            insert(x);
        else
            if(find(x))
                printf("Yes\n");
            else
                printf("No\n");
    }
    return 0;
}