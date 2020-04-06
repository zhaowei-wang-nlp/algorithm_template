#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 12, M = 1 << N;

int n, m;
long long f[N][M];
bool st[M];
//这个题用状态压缩dp, 如果想用1x2的小方格平铺一个长方形的话，只要确定所有横向的小方格位置，纵向小方格就有唯一的解了
//所以枚举每一列可以如何放横向的方格。f[i][j]代表的是第i列的放法j，j的每一位代表一行，如果某一位为1，则在该行放一个小方格
//当前列的方法不能上一列有冲突，因为上一列的1x2方格会申出来一个1x1方格到当前列
//同时，因为每一列的空白位置要放入竖直的1x2方格，所以每一列在放横向方格的时候要保证两个1x2方格之间的距离是偶数
int main()
{
    while(cin >> n >> m, n || m)
    {
        for(int i = 0; i < 1 << n; i ++)//枚举一下每一种放横向方格的方法的空白地方是否能让竖向方格填充
        {
            int cnt = 0;
            st[i] = true;
            for(int j = 0; j < n; j ++)
                if(i >> j & 1)//如果当前位是1的话，那么看一下cnt是不是奇数，如果是奇数说明两个横向方格之间的空白符有奇数个，状态不合法
                {
                    if(cnt & 1) st[i] = false;
                    cnt = 0;
                }
                else cnt ++;
            if(cnt & 1) st[i] = false;//最后一段空白可能不以1结尾
        }
        
        memset(f, 0, sizeof f);
        f[0][0] = 1; //这里的列数应该从1开始，然后我们多加一个第0列，第0列不能放方格所以f[0][0]为1，其他元素为0
        for(int i = 1; i <= m; i ++)
            for(int j = 0; j < 1 << n; j ++)
                for(int k = 0; k < 1 << n; k ++)
                    if((j & k) == 0 && st[j | k])//枚举一下上一列的状态，如果不和当前列冲突，并且j|k可以放竖直方格则合法
                        f[i][j] += f[i - 1][k];
        cout << f[m][0] << endl; //最后一列不能放方格
    }
}