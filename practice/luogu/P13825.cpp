#include<bits/extc++.h>
#define int unsigned long long
#define ls lson[rt]
#define rs rson[rt]
using namespace std;
const int maxn = 1e5 + 5;
int n,m,cnt = 1;
int lson[maxn << 6],rson[maxn << 6];
struct Nahida
{
    int sum,tag;
    void tag_down(int l,int r,int x)
    {
        sum += (r - l + 1) * x;
        tag += x;
    }
}tree[maxn << 6];
int calc(int l,int r){return (l + r) * (r - l + 1) >> 1;}
void push_up(int rt){tree[rt].sum = tree[ls].sum + tree[rs].sum;}
void push_down(int l,int r,int rt)
{
    if (!ls)
        ls = ++cnt;
    if (!rs)
        rs = ++cnt;
    int mid = (l + r) >> 1,&tag = tree[rt].tag;
    if (!tag)
        return;
    tree[ls].tag_down(l,mid,tag);
    tree[rs].tag_down(mid + 1,r,tag);
    tag = 0;
}
void upd(int ql,int qr,int x,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt].tag_down(l,r,x);
    int mid = (l + r) >> 1;
    push_down(l,r,rt);
    if (ql <= mid)
        upd(ql,qr,x,l,mid,ls);
    if (qr > mid)
        upd(ql,qr,x,mid + 1,r,rs);
    push_up(rt);
}
int que(int ql,int qr,int l = 1,int r = n,int rt = 1)
{
    if (!rt)    
        return 0;
    if (ql <= l && r <= qr)
        return tree[rt].sum;
    int mid = (l + r) >> 1,res = 0;
    push_down(l,r,rt);
    if (ql <= mid)
        res += que(ql,qr,l,mid,ls);
    if (qr > mid)
        res += que(ql,qr,mid + 1,r,rs);
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int op,l,r,x;
    while (m--)
    {
        cin >> op >> l >> r;
        if (op == 1)
        {
            cin >> x;
            upd(l,r,x);
        }
        else
            cout << que(l,r) + calc(l,r) << '\n';
    }
    return 0;
}