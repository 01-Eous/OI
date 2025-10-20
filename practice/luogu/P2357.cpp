#include<bits/extc++.h>
#define int long long
#define ls rt << 1
#define rs rt << 1 | 1
using namespace std;
const int maxn = 2e5 + 5;
int n,m;
struct Nahida
{
    int sum,tag;
    void tag_down(int l,int r,int x)
    {
        sum += (r - l + 1) * x;
        tag += x;
    }
}tree[maxn << 2];
void push_up(int rt){tree[rt].sum = tree[ls].sum + tree[rs].sum;}
void push_down(int l,int r,int rt)
{
    int &tag = tree[rt].tag;
    if (!tag)
        return;
    int mid = (l + r) >> 1;
    tree[ls].tag_down(l,mid,tag);
    tree[rs].tag_down(mid + 1,r,tag);
    tag = 0;
}
void build(int l,int r,int rt)
{
    tree[rt].tag = 0;
    if (l == r)
    {
        cin >> tree[rt].sum;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd1(int ql,int qr,int x,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt].tag_down(l,r,x);
    push_down(l,r,rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd1(ql,qr,x,l,mid,ls);
    if (qr > mid)
        upd1(ql,qr,x,mid + 1,r,rs);
    push_up(rt);
}
void upd2(int pos,int x,int l = 1,int r = n,int rt = 1)
{
    if (l == r)
    {
        tree[rt].sum += x;
        return;
    }
    push_down(l,r,rt);
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd2(pos,x,l,mid,ls);
    else
        upd2(pos,x,mid + 1,r,rs);
    push_up(rt);
}
int que1(int ql,int qr,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt].sum;
    push_down(l,r,rt);
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res += que1(ql,qr,l,mid,ls);
    if (qr > mid)
        res += que1(ql,qr,mid + 1,r,rs);
    return res;
}
int que2(int pos,int l = 1,int r = n,int rt = 1)
{
    if (l == r)
        return tree[rt].sum;
    push_down(l,r,rt);
    int mid = (l + r) >> 1;
    if (pos <= mid)
        return que2(pos,l,mid,ls);
    else
        return que2(pos,mid + 1,r,rs);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    build(1,n,1);
    int op,l,r,k;
    while (m--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r >> k;
            upd1(l,r,k);
        }
        else if (op == 2)
        {
            cin >> k;
            upd2(1,k);
        }
        else if (op == 3)
        {
            cin >> k;
            upd2(1,-k);
        }
        else if (op == 4)
        {
            cin >> l >> r;
            cout << que1(l,r) << '\n';
        }
        else
            cout << que2(1) << '\n';
    }
    return 0;
}