#include<iostream>
using namespace std;
const int N = 1000010;
bool st[N];
int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i])
            cnt ++;
        for(int j = i + i; j <= n; j += i)
            st[j] = true;
    }
    printf("%d", cnt);
    return 0;
}