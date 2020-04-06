#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 10;
int get(vector<int> num, int l, int r)
{
    int res = 0;
    for(int i = r; i >= l; i --) res = res * 10 + num[i];
    return res;
}
int power10(int x)
{
    int res = 1;
    while(x --) res *= 10;
    return res;
}
//以数字1234567为例, 如果我们要统计第四位有多少d
//xxxdyyy表示所有数字的一个通用表示形式,那么解有2类
//1. 当xxx<123的时候，解有123 * 10^3个(3代表有3个y, yyy的取值可以从000-999)
//第1类解只有在xxx长度不为0的时候才有，也就是统计的d不是数字最高位的情况
//2. 当xxx=123的时候，
    //2.1如果d < 4, 那么yyy可以取任意的数字, 从000-999
    //2.2如果d = 4, 那么yyy可以从000取到567,所以有568种解
    //2.3如果d > 4, 那么yyy没有合法的取值
//第2类解任何情况都有
//下面代码的注释写明了3种特例
int count(int n, int x)
{
    if(!n) return 0;
    vector<int> num;
    while(n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size();
    int res = 0;
    for(int i = n - 1 - !x; i >= 0; i --)//x是0的话，则x不可能在最高位
    {
        if(i < n - 1)//当i不是最高位的时候,才会有第一项
        {
            res += get(num, i + 1, n - 1) * power10(i);
            if(!x) res -= power10(i);//x是0的话,则x前面的数字不可能为0
        }
        if(num[i] == x) res += get(num, 0, i - 1) + 1;
        else if(num[i] > x) res += power10(i);
    }
    return res;
}
int main()
{
    int a, b;
    while(cin >> a >> b, a)
    {
        if(a > b) swap(a, b);

        for(int i = 0; i <= 9; i ++)
            cout << count(b, i) - count(a - 1, i) << " ";
        cout << endl;
    }

    return 0;
}