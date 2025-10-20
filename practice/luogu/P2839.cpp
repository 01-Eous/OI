#include<bits/extc++.h>
#define int long long
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 2e4 + 5;
int n,m,cnt;
int root[maxn],q[4];
pair<int,int> a[maxn];
struct Nahida
{
    int pre,suf,sum;
    int lson,rson;
}tree[maxn * 50];
int clone(int rt)
{
    tree[++cnt] = tree[rt];
    return cnt;
}
void push_up(int rt)
{
    tree[rt].pre = max(tree[ls].pre,tree[ls].sum + tree[rs].pre);
    tree[rt].suf = max(tree[rs].suf,tree[rs].sum + tree[ls].suf);
    tree[rt].sum = tree[ls].sum + tree[rs].sum;
}
int build(int l,int r)
{
    int rt = ++cnt;
    if (l == r)
    {
        tree[rt].pre = tree[rt].suf = tree[rt].sum = 1;
        return rt;
    }
    int mid = (l + r) >> 1;
    ls = build(l,mid);
    rs = build(mid + 1,r);
    push_up(rt);
    return rt;
}
int upd(int pos,int x,int l,int r,int rt)
{
    rt = clone(rt);
    if (l == r)
    {
        tree[rt].pre = tree[rt].suf = tree[rt].sum = x;
        return rt;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        ls = upd(pos,x,l,mid,ls);
    else
        rs = upd(pos,x,mid + 1,r,rs);
    push_up(rt);
    return rt;
}
int qsum(int ql,int qr,int l,int r,int rt)
{
    if (ql <= l && r <= qr)
        return tree[rt].sum;
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res += qsum(ql,qr,l,mid,ls);
    if (qr > mid)
        res += qsum(ql,qr,mid + 1,r,rs);
    return res;
}
int qpre(int ql,int qr,int l,int r,int rt)
{
    if (ql <= l && r <= qr)
        return tree[rt].pre;
    int mid = (l + r) >> 1;
    if (ql > mid)
        return qpre(ql,qr,mid + 1,r,rs);
    else if (qr <= mid)
        return qpre(ql,qr,l,mid,ls);
    else
        return max(qpre(ql,mid,l,mid,ls),qsum(ql,mid,l,mid,ls) + qpre(mid + 1,qr,mid + 1,r,rs));
}
int qsuf(int ql,int qr,int l,int r,int rt)
{
    if (ql <= l && r <= qr)
        return tree[rt].suf;
    int mid = (l + r) >> 1;
    if (ql > mid)
        return qsuf(ql,qr,mid + 1,r,rs);
    else if (qr <= mid)
        return qsuf(ql,qr,l,mid,ls);
    else
        return max(qsuf(mid + 1,qr,mid + 1,r,rs),qsum(mid + 1,qr,mid + 1,r,rs) + qsuf(ql,mid,l,mid,ls));
}
bool chk(int a,int b,int c,int d,int mid)
{
    int sum = 0;
    if (b + 1 <= c - 1)
        sum += qsum(b + 1,c - 1,1,n,root[mid]);
    sum += qsuf(a,b,1,n,root[mid]) + qpre(c,d,1,n,root[mid]);
    return sum >= 0;
}
int que(int a,int b,int c,int d)
{
    int l = 1,r = n,mid,res = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(a,b,c,d,mid))
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1,a + n + 1);
    root[1] = build(1,n);
    for (int i = 2; i <= n; i++)
        root[i] = upd(a[i - 1].second,-1,1,n,root[i - 1]);
    cin >> m;
    int lst = 0;
    while (m--)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> q[i];
            q[i] = (q[i] + lst) % n + 1;
        }
        sort(q,q + 4);
        cout << (lst = a[que(q[0],q[1],q[2],q[3])].first) << '\n';
    }
    return 0;
}