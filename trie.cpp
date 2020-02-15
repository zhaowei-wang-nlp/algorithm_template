#include<iostream>
using namespace std;
const int N = 100010;
char str[N];
int ne[N][26], index, cnt[N];//如果所有字符串长度相同则不需要cnt来标记字符串结尾
void insert()
{
    int p = 0;
    for(int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if(!ne[p][u]) ne[p][u] = ++ index;
        p = ne[p][u];
    }
    cnt[p] ++;
}
int query()
{
    int p = 0;
    for(int i = 0; str[i]; i ++)
    {
        int u = str[i] - 'a';
        if(!ne[p][u]) return 0;
        p = ne[p][u];
    }
    return cnt[p];
}
int main(){
    int m;
    string c;
    scanf("%d", &m);
    for(int i = 0; i < m; i ++)
    {
        cin >> c >> str;
        if(c == "I")
        {
            insert();
        }
        else if(c == "Q")
        {
            printf("%d\n", query());
        }
    }
    return 0;
}