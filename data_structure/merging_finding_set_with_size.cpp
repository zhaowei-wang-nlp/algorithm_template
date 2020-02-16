#include<iostream>
using namespace std;
const int N = 100010;
int p[N], s[N];
int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)//题目下标从1开始
    {
        p[i] = i;
        s[i] = 1;
    }
    string c;
    int a, b;
    for(int i = 0; i < m; i ++)
    {
        cin >> c;
        if(c == "C")
        {
            scanf("%d%d", &a, &b);
            a = find(a); b = find(b);
            if(a != b)//此处可能a和b在相同的块当中,此时不用更新size数组(s数组)，更不更新p都无所谓
            {
                s[b] += s[a];//当存储每个集合的大小的时候，只用和并集合的时候更新集合大小就行了
                p[a] = b;  //注意先更新集合大小，再合并集合
            }
        }
        else if(c == "Q1")
        {
            scanf("%d%d", &a, &b);
            if(find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
        }
        else if(c == "Q2")
        {
            scanf("%d", &a);
            printf("%d\n", s[find(a)]);
        }
    }
    return 0;
}