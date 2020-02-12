#include<iostream>
using namespace std;
const int N = 100010;
int e[N], l[N], r[N] = {1}, idx = 2;//要记得初始化
void insert(int k, int x)
{
    e[idx] = x; l[idx] = k; r[idx] = r[k]; l[r[k]] = idx; r[k] = idx; idx ++;
}

void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int main()
{
    int m, k, x;
    scanf("%d", &m);
    string c;//c是字符串
    for(int i = 0; i < m; i ++)
    {
        cin >> c;
        if(c == "L")
        {
            scanf("%d", &x);
            insert(0, x);
        }
        if(c == "R")
        {
            scanf("%d", &x);
            insert(l[1], x);
        }
        if(c == "D")
        {
            scanf("%d", &k);
            remove(k + 1);
        }
        if(c == "IL")
        {
            scanf("%d%d", &k, &x);
            insert(l[k + 1], x);
        }
        if(c == "IR")
        {
            scanf("%d%d", &k, &x);
            insert(k + 1, x);
        }
    }
    for(int i = r[0]; i != 1; i = r[i])//更新条件是i = r[i];
    {
        printf("%d ", e[i]);
    }
    return 0;
}