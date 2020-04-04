#include<iostream>
using namespace std;
const int N = 100010;
int num[N], last[N];// last[i]存储长度是i的上升子序列的最后一个数字
// 可以知道last数组是单调上升的, 所以可以用2分来找到小于当前数字的最大数
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        scanf("%d", &num[i]);
    
    last[0] = -2e9;
    int len = 0;//记录当前最长的上升子序列
    for(int i = 0; i < n; i ++)
    {
        int l = 0, r = len;
        while(l < r)//二分一下，在所有小于a[i]的数里面找到最大的那个
        {
            int mid = l + r + 1 >> 1;
            if(last[mid] < num[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);
        last[r + 1] = num[i]; // 由于r是小于a[i]的最后一个数，那么last[r+1]如果存在则大于a[i],如果不存在则初始化为a[i]
    }
    printf("%d", len);
    return 0;
}