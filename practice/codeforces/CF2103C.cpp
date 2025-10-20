#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 2e5 + 5;
int n,k,root,cnt;
int a[maxn],sum[maxn];
struct Nahida
{
    int min1,val;
    int lson,rson;
    Nahida():min1(inf),val(0),lson(0),rson(0){};
}tree[maxn << 2];
void push_up(int rt)
{
    tree[rt].val = tree[ls].val + tree[rs].val;
    tree[rt].min1 = min(tree[ls].min1,tree[rs].min1);
}
void upd(int x,int id,int l = -n,int r = n,int &rt = root)
{
    if (!rt)
    {
        rt = ++cnt;
        tree[cnt] = Nahida();
    }
    if (l == r)
    {
        tree[rt].val = 1;
        tree[rt].min1 = min(tree[rt].min1,id);
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        upd(x,id,l,mid,ls);
    else
        upd(x,id,mid + 1,r,rs);
    push_up(rt);
}
int que(int ql,int qr,int l = -n,int r = n,int rt = root)
{
    if (!rt)
        return inf;
    if (ql <= l && r <= qr)
        return tree[rt].min1;
    int mid = (l + r) >> 1,res = inf;
    if (ql <= mid)
        res = min(res,que(ql,qr,l,mid,ls));
    if (qr > mid)
        res = min(res,que(ql,qr,mid + 1,r,rs));
    return res;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1,x; i <= n; i++)
    {
        cin >> x;
        a[i] = x <= k ? 1 : -1;
    }
    int x = inf,y = inf;
    root = cnt = 0;
    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        if (sum[i] >= 0)
        {
            if (que(0,sum[i]) < i)
                return cout << "YES\n",void();
            x = min(x,i);
            upd(sum[i],i);
        }
    }
    reverse(a + 1,a + n + 1);
    root = cnt = 0;
    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        if (sum[i] >= 0)
        {
            if (que(0,sum[i]) < i)
                return cout << "YES\n",void();
            y = min(y,i);
            upd(sum[i],i);
        }
    }
    if (x + y < n)
        cout << "YES\n";
    else
        cout << "NO\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}