#include<bits/extc++.h>
#define int long long
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 5e5 + 5;
int n,m,cnt;
int a[maxn],root[maxn];
struct Nahida
{
    int cnt,sum;
    int lson,rson;
}tree[maxn * 50];
int clone(int rt)
{
    tree[++cnt] = tree[rt];
    return cnt;
}
int upd(int x,int l,int r,int rt)
{
    rt = clone(rt);
    tree[rt].cnt++,tree[rt].sum += x;
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    if (x <= mid)
        ls = upd(x,l,mid,ls);
    else
        rs = upd(x,mid + 1,r,rs);
    return rt;
}
int que(int ql,int qr,int l,int r,int f,int k)
{
    if (!(tree[qr].cnt - tree[ql].cnt))
        return 0;
    int tmp1 = tree[qr].cnt - tree[ql].cnt,tmp2 = tree[qr].sum - tree[ql].sum;
    if (l >= k + f)
        return tmp2 - ((((k + f) << 1) + tmp1 - 1) * tmp1 >> 1);
    if (r <= k + f)
        return ((((k + f) << 1) + tmp1 - 1) * tmp1 >> 1) - tmp2;
    int mid = (l + r) >> 1,tmp = tree[tree[qr].lson].cnt - tree[tree[ql].lson].cnt;
    return que(tree[ql].lson,tree[qr].lson,l,mid,f,k) + que(tree[ql].rson,tree[qr].rson,mid + 1,r,f + tmp,k);
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        root[i] = upd(a[i],1,1e6,root[i - 1]);
    }
    int l,r,k;
    while (m--)
    {
        scanf("%lld%lld%lld",&l,&r,&k);
        printf("%lld\n",que(root[l - 1],root[r],1,1e6,0,k));
    }
    return 0;
}