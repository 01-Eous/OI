#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,nn;
int a[maxn],num[maxn],tree[maxn];
int lowbit(int x){return x & -x;}
void upd(int i,int x)
{
    for (; i <= n; i += lowbit(i))
        tree[i] += x;
}
int que(int i)
{
    int res = 0;
    for (; i; i -= lowbit(i))
        res += tree[i];
    return res;
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        num[i] = a[i] += a[i - 1];
    }
    sort(num,num + n + 1);
    nn = unique(num,num + n + 1) - num;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        a[i] = lower_bound(num,num + nn,a[i]) - num + 1;
        ans += que(a[i] - 1);
        upd(a[i],1);
    }
    printf("%lld",ans);
    return 0;
}