#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int a[N], n;
// 这个题是个奥数题
// 把所有的数字从小到大排序, 第i大的和第i小的组成一组
// 对于每一组来说, 想让选择的点到这一组距离最小, 只需要选择的点再这一组点组成的区间中
// 1. 如果n是偶数的话, 会有n/2个区间, 选择的点要最小的区间中选择点
// 2. 如果n是奇数的话, 会有n/2个区间, 剩余一个点。 这个点可以看成一个起点和终点相同的点, 然后选择最小的区间, 也就是单独的那个点
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int p = a[n / 2], res = 0;
    for(int i = 0; i < n; i ++)
        res += abs(a[i] - a[n / 2]);
    cout << res;
    return 0;
}