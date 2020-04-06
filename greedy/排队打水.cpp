#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int a[N], n;
// 贪心策略: 每次选最小的
// 贪心选择性: 如果最有解的第一个数不是数组中最小的, 那么交换第一个数和最小的数, 可以得到更优的解
// 优化子结构: 把代价函数写出来, 可以发现父问题的代价是子问题的代价加一个常数
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    reverse(a, a + n);
    
    long long res = 0;
    for(int i = 0; i < n; i ++)
        res += a[i] * i;
    cout << res;
    return 0;
}