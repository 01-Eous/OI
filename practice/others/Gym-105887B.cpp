#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e6 + 5;
int n,m,idx;
int l[maxn],r[maxn],c[maxn],num[maxn];
struct Nahida
{
    int val,tag;
    void tag_down(int x){val += x,tag += x;}
}tree[maxn << 2];
void push_up(int rt){tree[rt].val = min(tree[ls].val,tree[rs].val);}
void push_down(int rt)
{
    int &tag = tree[rt].tag;
    if (!tag)
        return;
    tree[ls].tag_down(tag);
    tree[rs].tag_down(tag);
    tag = 0;
}
void build(int l,int r,int rt)
{
    tree[rt] = {0,0};
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
}
void upd(int ql,int qr,int x,int l = 1,int r = idx,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt].tag_down(x);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,x,l,mid,ls);
    if (qr > mid)
        upd(ql,qr,x,mid + 1,r,rs);
    push_up(rt);
}
int que(int x,int l = 1,int r = idx,int rt = 1)
{
    if (l == r)
        return tree[rt].val;
    push_down(rt);
    int mid = (l + r) >> 1;
    if (x <= mid)
        return que(x,l,mid,ls);
    else
        return que(x,mid + 1,r,rs);
}
void solve()
{
    cin >> m >> n;
    idx = 0;
    num[++idx] = 1,num[++idx] = m;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i] >> c[i];
        num[++idx] = l[i],num[++idx] = r[i];
    }
    sort(num + 1,num + idx + 1);
    idx = unique(num + 1,num + idx + 1) - num - 1;
    build(1,idx,1);
    for (int i = 1; i <= n; i++)
    {
        l[i] = lower_bound(num + 1,num + idx + 1,l[i]) - num;
        r[i] = lower_bound(num + 1,num + idx + 1,r[i]) - num;
        if (l[i] != r[i])
            upd(l[i],r[i] - 1,c[i]);
    }
    int ans = inf;
    for (int i = 1; i < idx; i++)
        ans = min(ans,que(i));
    cout << ans << '\n';
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