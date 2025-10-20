#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n;
char s[maxn];
int sum[maxn],bel[maxn],dp[maxn];
deque<int> q[maxn];
struct 永远喜欢纳西妲{int l,r,val;}tree[maxn << 2];
void push_up(int rt){tree[rt].val = max(tree[ls].val,tree[rs].val);}
void build(int l,int r,int rt)
{
    tree[rt].l = l,tree[rt].r = r;
    tree[rt].val = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
}
void upd(int pos,int x,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (l == r)
    {
        tree[rt].val = x;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,x,ls);
    else
        upd(pos,x,rs);
    push_up(rt);
}
int que(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].val;
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res = max(res,que(ql,qr,ls));
    if (qr > mid)
        res = max(res,que(ql,qr,rs));
    return res;
}
signed main()
{
    scanf("%s",s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        bel[i] = bel[i - 1] + (s[i] == '(' ? 1 : -1);
    build(1,n,1);
    dp[0] = sum[0] = 1;
    q[0].push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int lst = que(1,bel[i] - 1);
        while (!q[bel[i]].empty() && q[bel[i]].front() < lst)
        {
            sum[bel[i]] -= dp[q[bel[i]].front()];
            q[bel[i]].pop_front();
        }
        dp[i] = (dp[i - 1] + sum[bel[i]]) % mod;
        sum[bel[i]] += dp[i];
        q[bel[i]].push_back(i);
        upd(bel[i],i);
    }
    cout << dp[n];
    return 0;
}