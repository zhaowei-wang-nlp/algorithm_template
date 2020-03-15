#include<iostream>
#include<cmath>
using namespace std;
const int N = 110;
double a[N][N];
int n;
const double eps = 1e-6;
int gauss()
{
    int r, c;
    for(c = 0, r = 0; c < n;  c++)
    {
        int t = r;
        for(int i = r; i < n; i ++)
        {
            if(fabs(a[i][c]) > fabs(a[t][c]))
            {
                t = i;
            }
        }
        
        if(fabs(a[t][c]) < eps)//记着判断最大的数是不是0
            continue;
        for (int i = c; i < n + 1; i ++ ) swap(a[t][i], a[r][i]);
            
        for(int i = n ; i >= c; i --)
            a[r][i] /= a[r][c];
            
        for(int i = r + 1; i < n; i ++)
            if(fabs(a[i][c]) > eps)
                for(int j = n; j >= c; j --)
                {
                    a[i][j] -= a[i][c] * a[r][j];
                }
        r ++;
    }
    if(r < n)
    {
        for(int i = r; i < n; i ++)
            if(fabs(a[i][n]) > eps)
                return 2;
        return 1;
    }
    
    for(int i = n - 1; i >= 0; i --)
    {
        for(int j = i - 1; j >= 0; j --)
        {
            a[j][n] -= a[j][i] * a[i][n];
        }
    }
    return 0;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= n ; j ++)
            cin >> a[i][j];
    
    int t = gauss();
    
    if(!t)
    for(int i = 0; i < n; i ++) printf("%.2lf\n", a[i][n]);
    else if(t == 1)
        puts("Infinite group solutions");
    else
        puts("No solution");
        
    return 0;
}
