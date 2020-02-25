#include<iostream>
#include<vector>
using namespace std;
class abc
{
    public:
        int l = 1;
};
int main()
{
    vector<abc> a;
    abc b;
    a.push_back(b);
    b.l = 2;
    printf("%d", a.back().l);
    printf("%d", b.l);
    system("pause");
    return 0;
}