#include<iostream>
#include<cstring>
using namespace std;
const int N = 510, M = 10010;
int dist[N], last[N], n, m, k;
struct Edge
{
    int a, b, w;
}edges[M];
//bellman_ford算法可以求长度不超过K的最短路
int main()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i ++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edges[i].a = a, edges[i].b = b, edges[i].w = c;
        }
    for(int i = 0; i < k; i ++)//第i次循环得到长度不超过i的路，每次迭代长度可能的最大值加一
    {
        memcpy(last, dist, sizeof dist);//这里要备份一下，i+1次的结果应该完完全全基于第i次的结果
        for(int j = 0; j < m; j ++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if(dist[b] > last[a] + w)
                dist[b] = last[a] + w;
        }
    }
    if(dist[n] > 0x3f3f3f3f/2) printf("impossible");
    else printf("%d", dist[n]);
    return 0;
}