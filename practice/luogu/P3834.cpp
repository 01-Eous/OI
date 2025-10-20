#include<bits/extc++.h>
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 2e5 + 5;
int n,q,m,cnt,idx;
int a[maxn],num[maxn],root[maxn];
inline void read(int &x)
{
    int f = 1;x = 0;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
struct Nahida{int val,lson,rson;}tree[maxn * 25];
int clone(int rt)
{
    cnt++;
    tree[cnt].lson = ls;
    tree[cnt].rson = rs;
    tree[cnt].val = tree[rt].val + 1;
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
    read(n),read(q);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        num[++idx] = a[i];
    }
    sort(num + 1,num + idx + 1);
    m = unique(num + 1,num + idx + 1) - num - 1;
    root[0] = build(1,m);
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(num + 1,num + m + 1,a[i]) - num;
        root[i] = upd(a[i],1,m,root[i - 1]);
    }
    int l,r,k;
    while (q--)
    {
        read(l),read(r),read(k);
        printf("%d\n",num[que(root[l - 1],root[r],1,m,k)]);
    }
    return 0;
}