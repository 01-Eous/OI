// 最终选择了赛格门特吹神力
#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n,m,d,a,nn;
int p[maxn],pos[maxn],b[maxn];
int tree[maxn << 2],num[maxn],dp[maxn];
void push_up(int rt){tree[rt] = max(tree[ls],tree[rs]);}
void build(int l,int r,int rt)
{
    if (l == r)
    {
        tree[rt] = ~inf;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int pos,int x,int l = 1,int r = nn,int rt = 1)
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
    push_up(rt);
}
int que(int ql,int qr,int l = 1,int r = nn,int rt = 1)
{
    if (ql > qr)
        return ~inf;
    if (ql <= l && r <= qr)
        return tree[rt];
    int mid = (l + r) >> 1,res = ~inf;
    if (ql <= mid)
        res = max(res,que(ql,qr,l,mid,ls));
    if (qr > mid)
        res = max(res,que(ql,qr,mid + 1,r,rs));
    return res;
}
signed main()
{
    scanf("%lld%lld%lld%lld%lld",p,&m,&d,&a,&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld",p + i,b + i);
    p[++n] = m;
    for (int i = 0; i <= n; i++)
    {
        pos[i] = p[i] % d;
        num[++nn] = pos[i];
    }
    sort(num + 1,num + nn + 1);
    nn = unique(num + 1,num + nn + 1) - num - 1;
    for (int i = 0; i <= n; i++)
        pos[i] = lower_bound(num + 1,num + nn + 1,pos[i]) - num;
    build(1,nn,1);
    dp[0] = 0;
    upd(pos[0],dp[0] + p[0] / d * a);
    for (int i = 1; i <= n; i++)
    {
        int max1 = que(1,pos[i] - 1) - a;
        int max2 = que(pos[i],nn);
        dp[i] = b[i] + max(max1,max2) - p[i] / d * a;
        upd(pos[i],dp[i] + p[i] / d * a);
    }
    printf("%lld",dp[n]);
    return 0;
}