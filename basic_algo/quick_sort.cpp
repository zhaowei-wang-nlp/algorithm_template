#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];
void quick_sort(int q[], int l, int r){
    if (l >= r) return;
    int x = q[l], i = l - 1, j = r + 1;
    while (i < j){
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j){
            swap(q[i], q[j]);
        } 
    }
    /*
    1.最后区间划分使用i-1,i还是j,j+1取决于x的取值。
    如果x = q[l]那么只能用j和j+1，因为可能在while第一次循环中j减到了0，此时i必然是0，
    因为q[i] == x。那么如果写区间划分写i-1,i，那么[i, r]等于[l, r]，将引起无穷递归。
    如果x = q[r]，同理只能写i-1,i。
    2.如果用x=q[l+r>>1]或者x=q[l+r+1>>1]。那么只会在数组长度为2事产生边界错误。如果
    数组长度大于2，那么l+r>>1和l+r+1>>1都不会等于l也不会等于r，那么不会出现while只
    循环1次的情况。当数组长度为2的时候，很明显l+r>>1等于l，l+r+1>>1等于r，用第1条的
    规则分析用i还是j分割数据即可。
    */
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++ ) scanf("%d", &q[i]);
    quick_sort(q, 0, n-1);
    for(int i = 0; i < n; i ++) printf("%d ", q[i]);
    return 0;
}