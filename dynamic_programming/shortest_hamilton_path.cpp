#include<iostream>
#include<cstring>
using namespace std;
const int N = 20, M = 1 << N;
int f[M][N], n, w[N][N];
//求哈密顿路也用状态压缩dp, f[i][j]表示路径经过点集为i的末尾为点j的路径集合
//由于f[i][j] = min(f[i][j], f[i - {j}][k] + w[k][j]) (遍历所有点k) 中需要用到i-{j}的f值
//所以我们以点集为行坐标，从点集小到大的计算所有f，而不是让路径最后一个点作为横坐标
int main()
{
    cin >> n;
    for(int i = 0; i < n ; i ++)
        for(int j = 0; j < n; j ++)
            cin >> w[i][j];
    
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;//初始化
    for(int i = 2; i < 1 << n; i ++)//从点集为2开始枚举
        for(int j = 0; j < n; j ++)
            if(i >> j & 1)
            {
                int path = i - (1 << j);
                
                for(int k = 0; k < n; k ++)
                    f[i][j] = min(f[i][j], f[path][k] + w[k][j]);
            }
    cout << f[(1 << n) - 1][n - 1];
    return 0;
}