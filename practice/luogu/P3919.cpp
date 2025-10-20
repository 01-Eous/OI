#include<bits/extc++.h>
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 1e6 + 5;
int n,m,cnt;
int a[maxn],root[maxn];
struct Nahida{int lson,rson,val;}tree[maxn * 25];
void read(int &x)
{
    int f = 1;x = 0;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
int clone(int rt)
{
    tree[++cnt] = tree[rt];
    return cnt;
}
int build(int l,int r,int rt)
{
    rt = ++cnt;
    if (l == r)
    {
        tree[rt].val = a[l];
        return rt;
    }
    int mid = (l + r) >> 1;
    ls = build(l,mid,ls);
    rs = build(mid + 1,r,rs);
    return rt;
}
int upd(int pos,int x,int l,int r,int rt)
{
    rt = clone(rt);
    if (l == r)
    {
        tree[rt].val = x;
        return rt;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        ls = upd(pos,x,l,mid,ls);
    else
        rs = upd(pos,x,mid + 1,r,rs);
    return rt;
}
int que(int pos,int l,int r,int rt)
{
    if (l == r)
        return tree[rt].val;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        return que(pos,l,mid,ls);
    else
        return que(pos,mid + 1,r,rs);     
}
signed main()
{
    read(n),read(m);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    root[0] = build(1,n,1);
    int ver,op,pos,x;
    for (int i = 1; i <= m; i++)
    {
        read(ver),read(op),read(pos);
        if (op == 1)
        {
            read(x);
            root[i] = upd(pos,x,1,n,root[ver]);
        }
        else
        {
            printf("%d\n",que(pos,1,n,root[ver]));
            root[i] = root[ver];
        }
    }
    return 0;
}