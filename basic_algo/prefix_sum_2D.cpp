#include<iostream>
using namespace std;
const int N = 1010, M = 1010;
int q[N][M], S[N][M];
int main()
{
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf("%d", &q[i][j]);
            S[i+1][j+1] = S[i][j+1] + S[i+1][j] - S[i][j] + q[i][j];
        }
    int x1,y1,x2,y2;
    for(int i=0;i<p;i++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", S[x2][y2] - S[x2][y1-1] - S[x1-1][y2] + S[x1-1][y1-1]);
    }
}