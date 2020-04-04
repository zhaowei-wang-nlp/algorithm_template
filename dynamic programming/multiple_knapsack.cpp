#include<iostream>
#include<algorithm>
using namespace std;
const int N = 12010, M = 2010;
int n, m;
int v[N], w[N], f[M];
int main()
{
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while(k <= s)// 这个地方把s用2的整数次幂之和的形式表示，每一个2的整数次幂看成一个物品
        {
            cnt ++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k <<= 1;
        }
        if(s > 0)
        {
            cnt ++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    
    n = cnt;
    
    for(int i = 1; i <= n; i ++)// 最后用一个01背包问题解决多重背包问题
        for(int j = m; j >= v[i]; j --)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    cout << f[m] << endl;
    return 0;
}