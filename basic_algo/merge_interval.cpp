#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
void merge(vector<PII> &segs)
{
    sort(segs.begin(), segs.end());//记得排序
    
    int st = -2e9, ed = -2e9;
    vector<PII> res;
    
    for(auto seg : segs)
    {
        if(seg.first > ed)
        {
            if(st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);
    }
    if(st != -2e9) res.push_back({st, ed});//记得输出最后一个，并且输出前要判断是否有区间。
    segs = res;
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<PII> segs;
    for(int i = 0; i < n; i ++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }
    
    merge(segs);
    
    printf("%d", segs.size());
    return 0;
}