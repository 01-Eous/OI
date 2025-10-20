#include<bits/extc++.h>
#define ls rt << 1
#define rs rt << 1 | 1
using namespace std;
const int maxn = 1e5 + 5;
int n,q;
struct Nahida
{
    int max1,max2;
    void push_up(const Nahida &lson,const Nahida &rson)
    {
        if (lson.max1 > rson.max1)
        {
            max1 = lson.max1;
            max2 = max(lson.max2,rson.max1);
        }
        else if (lson.max1 < rson.max1)
        {
            max1 = rson.max1;
            max2 = max(lson.max1,rson.max2);
        }
        else
            max1 = max2 = lson.max1;
    }
}tree[maxn << 2];
void build(int l,int r,int rt)
{
    if (l == r)
    {
        cin >> tree[rt].max1;
        tree[rt].max2 = -1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
void upd(int pos,int x,int l = 1,int r = n,int rt = 1)
{
    if (l == r)
    {
        tree[rt].max1 = x;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,x,l,mid,ls);
    else
        upd(pos,x,mid + 1,r,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
Nahida que(int ql,int qr,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt];
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return que(ql,qr,l,mid,ls);
    else if (ql > mid)
        return que(ql,qr,mid + 1,r,rs);
    Nahida tmp;
    tmp.push_up(
        que(ql,qr,l,mid,ls),
        que(ql,qr,mid + 1,r,rs)
    );
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    build(1,n,1);
    cin >> q;
    char op;
    int x,y;
    while (q--)
    {
        cin >> op >> x >> y;
        if (op == 'U')
            upd(x,y);
        else
        {
            Nahida tmp = que(x,y);
            cout << tmp.max1 + tmp.max2 << '\n';
        }
    }
    return 0;
}