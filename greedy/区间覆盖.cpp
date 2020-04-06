#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
struct Range
{
    int l, r;
    bool operator<(const Range & W)
    {
        return l < W.l;
    }
} range[N];
int n;
// 设目标区间是[st, ed]
// 贪心策略: 所有区间按左断点排序, 每次选左右左端点小于st的所有区间中最大的右端点rr, 如果rr < st则无解
// 如果rr >= ed则得到解，停止循环
// 贪心选择性: 设我们的策略选出的第一个区间是[l, r], 而最优解的区间是[l', r']
// 可以知道l <= st, l' <= st, 所以两个区间都可以覆盖st, 并且r >= r', 所以将[l', r']换为[l, r]得到的解仍然能覆盖[st, ed]
// 且区间数量没有增加
// 最优子结构: 设[st, ed]需要f(st, ed)个区间。选择第一个区间之后,剩余的目标区间为[st', ed],需要f(st', ed)个区间
// 可以知道f(st, ed) = f(st', ed) + 1, 所以f(st, ed)有最优解当且仅当f(st', ed)有最优解
// 所以[st, ed]的最优解包含子问题[st', ed]的最优解
int main()
{
    int st, ed, res = 0;
    cin >> st >> ed;
    cin >> n;
    for(int i = 0; i < n; i ++)
        scanf("%d%d", &range[i].l, &range[i].r);
    
    sort(range, range + n);

    for(int i = 0; i < n; i ++)
    {
        int j = i, r = -2e9;
        while(j < n && range[j].l <= st)
        {
            r = max(r, range[j].r);   
            j ++;
        }
        if(r < st)
        {
            res = -1;
            break;
        }
        res ++;
        st = r;
        if(st >= ed)
            break;
        i = j - 1;
    }
    if(res == -1 || st < ed)    cout << "-1";
    else printf("%d", res);
}