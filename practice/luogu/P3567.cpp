#include<bits/extc++.h>
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 5e5 + 5;
int n,m,cnt;
int a[maxn],root[maxn];
struct Nahida{int val,lson,rson;}tree[maxn * 50];
int clone(int rt)
{
    tree[++cnt] = tree[rt];
    tree[cnt].val++;
    return cnt;
}
int upd(int x,int l,int r,int rt)
{
    rt = clone(rt);
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    if (x <= mid)
        ls = upd(x,l,mid,ls);
    else
        rs = upd(x,mid + 1,r,rs);
    return rt;
}
int que(int ql,int qr,int l,int r,int k)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    if (tree[tree[qr].lson].val - tree[tree[ql].lson].val > (k >> 1))
        return que(tree[ql].lson,tree[qr].lson,l,mid,k);
    if (tree[tree[qr].rson].val - tree[tree[ql].rson].val > (k >> 1))
        return que(tree[ql].rson,tree[qr].rson,mid + 1,r,k);
    return 0;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        root[i] = upd(a[i],1,n,root[i - 1]);
    }
    int l,r;
    while (m--)
    {
        cin >> l >> r;
        cout << que(root[l - 1],root[r],1,n,r - l + 1) << '\n';
    }
    return 0;
}