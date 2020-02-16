#include<iostream>
using namespace std;
const int M = 100010;
int e[M], ne[M], head = -1, idx = 0;//要记得初始化 head 和 idx
void insert_to_head(int x)
{
    e[idx] = x; ne[idx] = head; head = idx; idx ++;
}
void insert(int k, int x)
{
    e[idx] = x; ne[idx] = ne[k]; ne[k] = idx; idx ++;
}
void del(int k)
{
    ne[k] = ne[ne[k]];
}
int main()
{
    char c;
    int m, k, x;
    scanf("%d", &m);
    for(int i = 0; i < m; i ++)
    {
        cin >> c;//c是字符型，别错写成整数
        if(c == 'H')
        {
            scanf("%d", &x);
            insert_to_head(x);
        }
        else if(c == 'D')
        {
            scanf("%d", &k);
            if(!k) head = ne[head];
            del(k - 1);
        }
        else if(c == 'I')
        {
            scanf("%d%d", &k, &x);
            insert(k - 1, x);
        }
    }
    for(int i = head; i != -1; i = ne[i])//更新条件是i = ne[i]，不是i++
    {
        printf("%d ", e[i]);
    }
    return 0;
}