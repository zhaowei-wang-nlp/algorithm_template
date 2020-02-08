#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> div(vector<int> A, int b, int &rem)
{
    int t = 0;
    vector<int> C;
    for(int i=A.size()-1; i>=0; i--)
    {
        t = 10 * t + A[i];
        C.push_back(t / b);
        t %= b;
    }
    reverse(C.begin(), C.end());
    while(C.size()>1 && C.back()==0) C.pop_back();
    rem = t;
    return C;
}
int main()
{
    string a;
    int b, rem;
    cin >> a >> b;
    vector<int> A;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i] - '0');
    vector<int> C = div(A, b, rem);
    for(int i=C.size()-1;i>=0;i--) printf("%d", C[i]);
    printf("\n%d", rem);
    return 0;
}