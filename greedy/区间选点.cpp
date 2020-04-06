#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;

int n;
struct Range
{
    int l, r;
    bool operator< (const Range &W)
    {
        return r < W.r;
    }
}range[N];
//这个题的贪心策略是选最小的右端点
//1.贪心选择性
//设x为最小的右端点，如果现在的最优解选取的最小的点是y，且y!=x
//设右端点最小的区间是[l, x], 那么y一定在[l, x]当中且有y < x
//设y覆盖的区间有k个，第i个为[li, ri], 那么ri >= x, 且 li <= y
//综上 li <= y < x <= ri, 则x也能覆盖这k个区间，所以可以把第一个点换成x
//2.优化子结构
//设总共有n个区间，x可以覆盖k个区间，那么设任意一种点的选取方法的点数为f(n)
//选取第一个点后剩余n-k个区间对应的点数为f(n - k)
//则f(n) = f(n - k) + 1, 求子问题的最优解等价于父问题的最优解
// 所以当前问题的最优解包括子问题的最优解
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d%d", &range[i].l, &range[i].r);

    sort(range, range + n);

    int res = 0, ed = -2e9;
    for(int i = 0; i < n; i ++)
    {// 此处应该在第一层循环选一个点之后,第二层pass掉所有已经选了的区间
     // 但是可以发现, 如果一个区间在选第一个点的时候被pass了
     // 那么选第二个点后，它还是被pass的，所以我们只用记录下当前最后一个点就行了
        if(range[i].l > ed)
        {
            res ++ ;
            ed = range[i].r;
        }
    }
    printf("%d", res);  
    return 0;
}