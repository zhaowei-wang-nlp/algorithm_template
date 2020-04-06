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
//这个题的贪心策略是选右端点最小的区间
//1.贪心选择性
//设x为右端点最小的区间，如果现在的最优解选取的第一个区间是y，且y!=x
//设x是[l, r], y为[l', r']。 y和其他选中的区间不冲突，由于r < r'，那么x也不会冲突
//2.优化子结构
//设总共有n个区间，x和k个区间冲突，那么设任意一种区间选取方法的区间数为f(n)
//选取第一个区间后剩余n-k个区间对应的区间数为f(n - k)
//则f(n) = f(n - k) + 1, 求子问题的最优解等价于父问题的最优解
// 所以当前问题的最优解包括子问题的最优解
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d%d", &range[i].l, &range[i].r);

    sort(range, range + n);

    int res = 0, ed = -2e9;
    for(int i = 0; i < n; i ++)
    {// 此处应该在第一层循环选一个区间之后,第二层pass掉所有已经冲突的区间
     // 但是可以发现, 如果一个区间在选第一个区间的时候被pass了
     // 那么选第二个区间后，它还是被pass的，所以我们只用记录下当前最后一个点就行了
        if(range[i].l > ed)
        {
            res ++ ;
            ed = range[i].r;
        }
    }
    printf("%d", res);  
    return 0;
}