#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1 << 20 | 5;
int n,q;
int a[maxn],ans[maxn][2];
void read(int &x)
{
    x = 0;
    int f = 1,ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
void merge(int l,int r,int dep)
{
    if (l + 1 >= r)
        return;
    int mid = (l + r) >> 1;
    merge(l,mid,dep - 1);
    merge(mid,r,dep - 1);
    int cnt = 0;
    for (int i = l; i < mid; i++)
        cnt += lower_bound(a + mid,a + r,a[i]) - (a + mid);
    ans[dep][0] += cnt;
    cnt = 0;
    for (int i = mid; i < r; i++)
        cnt += lower_bound(a + l,a + mid,a[i]) - (a + l);
    ans[dep][1] += cnt;
    sort(a + l,a + r);
}
signed main()
{
    read(n);
    for (int i = 0; i < (1 << n); i++)
        read(a[i]);
    merge(0,(1 << n),n);
    read(q);
    int x;
    while (q--)
    {
        read(x);
        for (int i = 1; i <= x; i++)
            swap(ans[i][0],ans[i][1]);
        int sum = 0;
        for (int i = 0; i <= n; i++)
            sum += ans[i][0];
        printf("%lld\n",sum);
    }
    return 0;
}