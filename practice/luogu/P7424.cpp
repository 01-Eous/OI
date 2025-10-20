#include<bits/extc++.h>
#define ls tree[rt].lson
#define rs tree[rt].rson
#define pii pair<int,int>
using namespace std;
const int maxn = 2e5 + 5;
int n,m,cnt;
int root[maxn],ans[maxn];
array<int,3> a[maxn];
pii b[maxn];
struct Nahida{int lson,rson,val;}tree[maxn * 30];
int clone(int rt)
{
    tree[++cnt] = tree[rt];
    tree[cnt].val++;
    return cnt;
}
int build(int l,int r)
{
    int rt = ++cnt;
    tree[rt].val = 0;
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    ls = build(l,mid);
    rs = build(mid + 1,r);
    return rt;
}
int upd(int pos,int l,int r,int rt)
{
    rt = clone(rt);
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        ls = upd(pos,l,mid,ls);
    else
        rs = upd(pos,mid + 1,r,rs);
    return rt;
}
int que(int ql,int qr,int l,int r,int k)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    int tmp = tree[tree[qr].lson].val - tree[tree[ql].lson].val;
    if (k <= tmp)
        return que(tree[ql].lson,tree[qr].lson,l,mid,k);
    else
        return que(tree[ql].rson,tree[qr].rson,mid + 1,r,k - tmp);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b + 1,b + m + 1);
    root[0] = build(1,m);
    for (int i = 1; i <= 2e5; i++)
    {
        static int j = 1;
        root[i] = root[i - 1];
        while (j <= m && b[j].first == i)
        {
            root[i] = upd(b[j].second,1,m,root[i]);
            j++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        auto &[l,r,k] = a[i];
        if (tree[root[r]].val - tree[root[l - 1]].val >= k)
            ans[que(root[l - 1],root[r],1,m,k)]++;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
    return 0;
}