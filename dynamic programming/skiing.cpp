#include<iostream>
#include<algorithm>
using namespace std;
const int N = 310;
int h[N][N], f[N][N], n, m;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
//这个题是一个记忆化搜索的题目
//当动态规划求状态数组f的遍历顺序不明确的时候，就应该使用递归求法来求f中的每一个数值
//这样做的好处是不用去根据转移方程想f的遍历顺序，坏处就是函数栈会占用空间
void get(int i, int j)
{
    if(f[i][j] != 0) return ;
    f[i][j] = 1;
    for(int k = 0; k < 4; k ++)
    {
        int x = i + dx[k], y = j + dy[k];
        if(x < n && x >= 0 && y < m && y >= 0 && h[x][y] > h[i][j])
        {
            get(x, y);
            f[i][j] = max(f[i][j], f[x][y] + 1);
        } 
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            scanf("%d", &h[i][j]);
    
    int ans = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            get(i, j);
            ans = max(ans, f[i][j]);
        }
    cout << ans;
    return 0;
}