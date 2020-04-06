#include<iostream>
#include<queue>
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
// 设当前区间为[l, r], 存储每一组最大的右端点max_r
// 如果l <= max_r 则存在冲突, 否则没有
// 将所有区间按左端点排序, 如果存在一组区间max_r < l则不冲突，否则冲突
// 这道题的做法不需要证明, 只需要证明max_r < l当且仅当当前区间不冲突, 这非常好证明, 所以这个题的做法就是按照定义进行的
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        range[i].l = a, range[i].r = b;
    }
    
    sort(range, range + n);
    
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0; i < n; i ++)
    {
        auto r = range[i];
        if(!heap.size() || heap.top() >= r.l) heap.push(r.r);
        else
        {
            heap.pop();
            heap.push(r.r);
        }
    }
    cout << heap.size();
    return 0;
}