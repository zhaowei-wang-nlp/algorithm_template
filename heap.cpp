#include<iostream>
using namespace std;
const int N = 100010;
int heap[N], index, hp[N], ph[N], cnt;
void heap_swap(int x, int y)
{
    swap(ph[hp[x]], ph[hp[y]]);
    swap(hp[x], hp[y]);
    swap(heap[x], heap[y]);
}
void down(int x)
{
    while(true)
    {
        int t = x;
        if(2 * x + 1 <= index && heap[2*x+1] < heap[t]) t = 2*x+1;
        if(2*x <= index && heap[2*x] < heap[t]) t = 2*x;
        if(t==x) break;
        heap_swap(t, x);
        x = t;
    }
}
void up(int x)
{
    while(x/2 && heap[x] < heap[x/2])
    {
        heap_swap(x, x/2);
        x = x / 2;
    }
}
int main()
{
    int n, k, x;
    string c;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        cin >> c;
        if(c == "I")
        {
            scanf("%d", &x);
            cnt ++; index ++;
            heap[index] = x;
            ph[cnt] = index;
            hp[index] = cnt;
            up(index);
        }
        else if(c == "PM")
        {
            printf("%d\n", heap[1]);
        }
        else if(c == "DM")
        {
            heap_swap(1, index);
            index --;
            down(1);
        }
        else if(c == "D")
        {
            scanf("%d", &k);
            int pk = ph[k];//此处要记录下来ph[k]
            heap_swap(pk, index);//因为再这一步交换ph[k]和 index之后,ph[k]会变化（等于index）
            index --;
            up(pk);
            down(pk);
        }
        else if(c == "C")
        {
            scanf("%d%d", &k, &x);
            heap[ph[k]] = x;
            up(ph[k]);
            down(ph[k]);
        }
    }
    return 0;
}