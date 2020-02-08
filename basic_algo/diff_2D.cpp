#include<iostream>
using namespace std;
const int N = 1010, M = 1010;
int q[N][M], b[N][M];
void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x2+1][y2+1] += c;
    b[x2+1][y1] -= c;
    b[x1][y2+1] -= c;
}
int main()
{
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d", &q[i][j]);
            insert(i,j,i,j,q[i][j]);
        }
    int x1, y1, x2, y2, c;
    for(int i=0;i<p;i++)
    {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            q[i][j] = q[i-1][j] + q[i][j-1] - q[i-1][j-1] + b[i][j];
            printf("%d ", q[i][j]);
        }
        printf("\n");
    }
}