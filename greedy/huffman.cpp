#include<iostream>
#include<queue>
using namespace std;
int  n;

int main()
{

    cin >> n;
    priority_queue<int, vector<int>, greater<int>> heap;
    int res = 0;
    for(int i = 0; i < n; i ++)
    {
        int a;
        scanf("%d", &a);
        heap.push(a);
    }
    while(heap.size() > 1)
    {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        res += a + b;
        heap.push(a + b);
    }
    cout << res;
    return 0;
}