bool check_high(int x) { }
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check_high(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
bool check_low(int x) { }
int bsearch_2(int l, int r)
{
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check_low(mid)) l = mid;
        else r = mid -1;
    }
    return l;
}
//binary search for float type
double bsearch_3(double l, double r)
{
    const double eps = 1e-6;
    while (r - l > eps)
    {
        double mid = (r + l) / 2;
        if (check_high(mid)) r = mid;
        else l = mid;
    }
    return l;
}
double bsearch_4(double l, double r)
{
    const double eps = 1e-6;
    for(int i = 0;i < 100; i ++)
    {
        double mid = (l + r) / 2;
        if (check_high(mid)) r = mid;
        else l = mid;
    }
    return l;
}