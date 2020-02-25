#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 100;
int maze[N][N], l[N][N];
int main()
{
    int m, n;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n;i ++)
        for(int j = 0; j < m; j ++)
            scanf("%d", &maze[i][j]);

    memset(l, -1, sizeof l);//距离数组要初始化为-1
    l[0][0] = 0;//第一个点的距离为0

    queue<PII> q;
    q.push({0,0});
    int x[4] = {1, 0,-1, 0}, y[4] = {0, 1, 0, -1};//这里bfs搜索的时候可以用两个数组来表示上下左右
    while(q.size())
    {
        PII t = q.front();
        q.pop();
        for(int i = 0; i < 4; i ++)
        {
            int a = t.first + x[i], b = t.second + y[i];
            if(a >= 0 && a < n && b >= 0 && b < m && !maze[a][b] && l[a][b] == -1)
            {
                l[a][b] = l[t.first][t.second] + 1;
                q.push({a, b});
            }
        }
    }
    printf("%d", l[n-1][m-1]);
    return 0;
}