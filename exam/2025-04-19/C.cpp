#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ld = long double;
const int maxn = 5e5 + 5;
int n,m,sb;
ld c[maxn],num[maxn],ans[maxn];
int op[maxn],f[maxn],t[maxn],b[maxn],pos[maxn],rnk[maxn];
struct Nahida
{
    int sumt;
    ld sumc;
}tree[maxn << 2];
void push_up(int rt)
{
    tree[rt].sumt = tree[ls].sumt + tree[rs].sumt;
    tree[rt].sumc = tree[ls].sumc + tree[rs].sumc;
}
void upd(int pos,int t,ld c,int l = 1,int r = n,int rt = 1)
{
    if (l == r)
    {
        tree[rt].sumt += t;
        tree[rt].sumc += t * c;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,t,c,l,mid,ls);
    else
        upd(pos,t,c,mid + 1,r,rs);
    push_up(rt);
}
int que_sumt(int ql,int qr,int l = 1,int r = n,int rt = 1)
{
    if (ql > qr)
        return 0;
    if (ql <= l && r <= qr)
        return tree[rt].sumt;
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res += que_sumt(ql,qr,l,mid,ls);
    if (qr > mid)
        res += que_sumt(ql,qr,mid + 1,r,rs);
    return res;
}
ld que_sumc(int ql,int qr,int l = 1,int r = n,int rt = 1)
{
    if (ql > qr)
        return 0;
    if (ql <= l && r <= qr)
        return tree[rt].sumc;
    int mid = (l + r) >> 1;
    ld res = 0;
    if (ql <= mid)
        res += que_sumc(ql,qr,l,mid,ls);
    if (qr > mid)
        res += que_sumc(ql,qr,mid + 1,r,rs);
    return res;
}
int que_kth(int k,int l = 1,int r = n,int rt = 1)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1,tmp = tree[ls].sumt;
    if (k <= tmp)
        return que_kth(k,l,mid,ls);
    else
        return que_kth(k - tmp,mid + 1,r,rs);
}
signed main()
{
    scanf("%lld",&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld",op + i,f + i);
        if (op[i] == 1)
        {
            scanf("%lld%lld",t + i,b + i);
            if (t[i])
                num[++n] = c[i] = f[i] + (ld)b[i] / t[i];
            else
                num[++n] = c[i] = inf;
            rnk[n] = i;
        }
    }
    sort(num + 1,num + n + 1);
    for (int i = 1; i <= m; i++)
    {
        if (op[i] == 1)
        {
            if (!t[i])
                sb += b[i];
            else
            {
                pos[i] = lower_bound(num + 1,num + n + 1,c[i]) - num;
                upd(pos[i],abs(t[i]),c[i]);
            }
        }
        else
        {
            int x = rnk[f[i]];
            if (!t[x])
                sb -= b[x];
            else
                upd(pos[x],-abs(t[x]),c[x]);
        }
        int tot = tree[1].sumt,med = que_kth((tot + 1) >> 1);
        int cnt = que_sumt(1,med);
        ld sumc = que_sumc(1,med);
        ans[i] += num[med] * cnt - sumc;
        cnt = que_sumt(med + 1,n);
        sumc = que_sumc(med + 1,n);
        ans[i] += sumc - num[med] * cnt;
        printf("%.6Lf\n",ans[i]);
    }
    return 0;
}