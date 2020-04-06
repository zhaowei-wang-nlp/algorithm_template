#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 50010;

int n;
PII cow[N];
// 贪心策略: 选择w+s最小的牛在最上面
// 贪心选择性: 可以证明如果最优解中w+s最小的牛不是在最上面，可以通过交换把它换到最上面，并且新序列的也是最优解
// 优化子结构: 当我们选择了w+s最小的牛的话, 子问题中牛的风险值比父问题的风险值小一个常数。 显然父问题的最优解包含子问题的最优解。
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        int w, s;
        scanf("%d%d", &w, &s);
        cow[i] = {w + s, w};
    }
    
    sort(cow, cow + n);
    int res = -2e9, sum = 0;
    for(int i = 0; i < n; i ++)
    {
        int w = cow[i].second, s = cow[i].first - cow[i].second;
        res = max(res, sum - s);
        sum += w;
    }
    cout << res;
    return 0;
}