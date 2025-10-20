#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,m;
struct Tribbie
{
    #define ls tree[rt].lson
    #define rs tree[rt].rson
    struct Nahida{int val,lson,rson;}tree[maxn << 5];
    int root[maxn],cnt;
    int clone(int rt)
    {
        tree[++cnt] = tree[rt];
        return cnt;
    }
    int build(int l,int r,bool op)
    {
        int rt = ++cnt;
        if (l == r)
        {
            tree[rt].val = op ? 1 : l;
            return rt;
        }
        int mid = (l + r) >> 1;
        ls = build(l,mid,op);
        rs = build(mid + 1,r,op);
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
        if(pos <= mid)
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
    #undef ls
    #undef rs
}fa,siz;
int find(int ver,int x)
{
    while (fa.que(x,1,n,fa.root[ver]) != x)
        x = fa.que(x,1,n,fa.root[ver]);
    return x;
}
void merge(int ver,int x,int y)
{
    x = find(ver,x),y = find(ver,y);
    if (x == y)
        return;
    int sx = siz.que(x,1,n,siz.root[ver]),sy = siz.que(y,1,n,siz.root[ver]);
    if (sx <= sy)
    {
        fa.root[ver] = fa.upd(x,y,1,n,fa.root[ver]);
        siz.root[ver] = siz.upd(y,sx + sy,1,n,siz.root[ver]);
    }
    else
    {
        fa.root[ver] = fa.upd(y,x,1,n,fa.root[ver]);
        siz.root[ver] = siz.upd(x,sx + sy,1,n,siz.root[ver]);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    fa.root[0] = fa.build(1,n,0);
    siz.root[0] = siz.build(1,n,1);
    int op,a,b;
    for (int i = 1; i <= m; i++)
    {
        cin >> op >> a;
        fa.root[i] = fa.root[i - 1];
        siz.root[i] = siz.root[i - 1];
        if (op == 1)
        {
            cin >> b;
            merge(i,a,b);
        }
        else if (op == 2)
        {
            fa.root[i] = fa.root[a];
            siz.root[i] = siz.root[a];
        }
        else
        {
            cin >> b;
            cout << (find(i,a) == find(i,b)) << '\n';
        }
    }
    return 0;
}