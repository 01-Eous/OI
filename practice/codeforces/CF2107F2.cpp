#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e6 + 5;
int n;
int a[maxn],dp[maxn],ans[maxn];
struct line
{
    int k,b;
    int f(int x){return k * x + b;}
}tree[maxn << 2];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
void build(int l,int r,int rt)
{
    tree[rt] = {0,inf};
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
}
void upd(line ln,int l = 1,int r = n,int rt = 1)
{
    int lp = tree[rt].f(l),rp = tree[rt].f(r);
    int lq = ln.f(l),rq = ln.f(r);
    if (lq <= lp && rq <= rp)
        tree[rt] = ln;
    else if (lq < lp || rq < rp)
    {
        int mid = (l + r) >> 1;
        if (ln.f(mid) < tree[rt].f(mid))
            swap(ln,tree[rt]);
        if (ln.f(l) < tree[rt].f(l))
            upd(ln,l,mid,ls);
        else
            upd(ln,mid + 1,r,rs);
    }
}
int que(int pos,int l = 1,int r = n,int rt = 1)
{
    int res = tree[rt].f(pos);
    if (l == r)
        return res;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        res = min(res,que(pos,l,mid,ls));
    else
        res = min(res,que(pos,mid + 1,r,rs));
    return res;
}
void solve()
{
    n = read();
    build(1,n,1);
    stack<int> stk;
    stk.push(0);
    for (int i = 1,j; i <= n; i++)
    {
        a[i] = read();
        while (a[j = stk.top()] > a[i])
            stk.pop();
        dp[i] = dp[j] + i - j - 1 + (i - j) * a[i];
        upd({a[i] + 2,dp[i] - (a[i] + 2) * i});
        ans[i] = que(i),stk.push(i);
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ",ans[i]);
    putchar('\n');
}
signed main()
{
    int t = read();
    while (t--)
        solve();
    return 0;
}