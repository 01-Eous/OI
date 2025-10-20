#include<bits/extc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 2e5 + 5;
int n;
int tree[maxn << 3],dp[maxn];
struct interval
{
    int l,r;
    bool operator<(const interval &x){return r < x.r;}
}a[maxn];
void upd(int pos,int x,int l = 1,int r = n << 1,int rt = 1)
{
    if (l == r)
    {
        tree[rt] = max(tree[rt],x);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,x,l,mid,ls);
    else
        upd(pos,x,mid + 1,r,rs);
    tree[rt] = max(tree[ls],tree[rs]);
}
int que(int ql,int qr,int l = 1,int r = n << 1,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt];
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res = max(res,que(ql,qr,l,mid,ls));
    if (qr > mid)
        res = max(res,que(ql,qr,mid + 1,r,rs));
    return res;
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        auto &[l,r] = a[i];
        scanf("%d%d",&l,&r);
        if (l > r)
            swap(l,r);
    }
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        auto [l,r] = a[i];
        dp[i] = que(l,r) + 1;
        upd(l,dp[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans,dp[i] + que(a[i].r,n << 1));
    printf("%d",ans);
    return 0;
}