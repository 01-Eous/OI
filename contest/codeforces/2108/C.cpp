#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n;
int tree[maxn << 2];
int a[maxn],dp[maxn];
int lft[maxn],rht[maxn];
void build(int l,int r,int rt)
{
    tree[rt] = inf;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
}
void upd(int ql,int qr,int x,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
    {
        tree[rt] = min(tree[rt],x);
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,x,l,mid,ls);
    if (qr > mid)
        upd(ql,qr,x,mid + 1,r,rs);
}
int que(int pos,int res = inf,int l = 1,int r = n,int rt = 1)
{
    res = min(res,tree[rt]);
    if (l == r)
        return res;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        return que(pos,res,l,mid,ls);
    else
        return que(pos,res,mid + 1,r,rs);
}
void solve()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    a[0] = a[n + 1] = inf;
    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] <= a[i])
            lft[i] = lft[i - 1];
        else
            lft[i] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        if (a[i] >= a[i + 1])
            rht[i] = rht[i + 1];
        else
            rht[i] = i;
    }
    build(1,n,1);
    for (int i = 1; i <= n; i++)
        upd(lft[i],rht[i],lft[i]);
    for (int i = 1; i <= n; i++)
    {
        int j = que(i);
        dp[i] = dp[j - 1] + 1;
    }
    printf("%lld\n",dp[n]);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}