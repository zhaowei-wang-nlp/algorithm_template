#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 100010;
int h[N], e[N], ne[N], idx, v[N];
bool st[N];
int dist[N], n, m;
void add(int a, int b, int c)
{
    v[idx] = c; e[idx] = b; ne[idx] = h[a]; h[a] = idx; idx ++;
}
//堆优化版的dijkstra的时间复杂度是O(mlogn)
int main()
{
    memset(h, -1, sizeof h);
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while(heap.size())//这里就不是循环n次了,是堆不空
    {
        PII t = heap.top();
        heap.pop();
        if(st[t.second]) continue;//由于堆中可能有一个点的多个dist,所以要判断当前最短dist的点是否被访问过
        st[t.second] = true;
        for(int i = h[t.second]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t.second] + v[i])
            {
                dist[j] = dist[t.second] + v[i];
                heap.push({dist[j], j});//如果dist距离变小了就把新的dist加入堆中
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f)
        printf("-1");
    else
        printf("%d", dist[n]);
    return 0;
}