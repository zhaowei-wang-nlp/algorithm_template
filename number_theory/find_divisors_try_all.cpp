#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    vector<int> q;
    scanf("%d", &n);
    while(n--)
    {
        q.clear();
        int a;
        scanf("%d", &a);
        for(int i = 1; i <= a/i; i ++)
        {
            if(a % i == 0)
            {
                q.push_back(i);
                if(i != a / i)
                {
                    q.push_back(a/i);
                }
            }
        }
        for(int i = 0; i < q.size(); i += 2)
            printf("%d ", q[i]);
        int bias = q.size() % 2 + 1;
        for(int i = q.size()-bias; i >= 0; i -= 2)
            printf("%d ", q[i]);
        printf("\n");
    }
    return 0;
}