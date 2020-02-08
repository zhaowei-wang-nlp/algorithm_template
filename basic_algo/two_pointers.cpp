#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int> a = {1,2};
bool check(int i, int j)
{

}
int main()
{
    int n, ans = 0;
    for(int i = 0, j = 0; i < n; i ++)
    {
        //更新状态
        while(j < i && check(i, j))//此处第一个限制条件不一定是j<i，但是一定要写一个j的限制条件。
                                   //比如j从n-1开始，条件就是j>=0
        {   
            //更新状态
            j ++;
        }
        //计算答案
    }
    printf("%d", ans);
    return 0;
}