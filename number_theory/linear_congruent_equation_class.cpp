#include<iostream>

using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main()
{
    int n;
    cin >> n;
    
    LL m1, a1, x = 0;
    cin >> m1 >> a1;
    n--;
    while(n --)
    {
        LL m2, a2;
        cin >> m2 >> a2;
        LL k1, k2;
        LL d = exgcd(m1, m2, k1, k2);
        k2 = -k2;
        if((a2 - a1) % d)
        {
            x = -1;
            break;
        }
        
        k1 *= (a2 - a1) / d;
        LL t = m2/d;
        k1 = ((k1%t) + t) % t;
        
        a1 = m1*k1 + a1;
        m1 = m1 / d * m2;
    }
    if(!x)
        printf("%ld", (a1%m1+m1)%m1);
    else
        puts("-1");
    return 0;
}