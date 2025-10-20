#include<bits/extc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define int long long
using namespace std;
const int maxn  = 3e5 + 5;
int n,m,w;
struct Klee{int pos,l,r,f;};
struct Nahida{int l,r,val,tag;}tree[maxn << 2];
vector<Klee> a;
void push_up(int rt){tree[rt].val = max(tree[ls].val,tree[rs].val);}
void push_down(int rt)
{
    tree[ls].val += tree[rt].tag,tree[rs].val += tree[rt].tag;
    tree[ls].tag += tree[rt].tag,tree[rs].tag += tree[rt].tag;
    tree[rt].tag = 0;
}
void build(int l,int r,int rt = 1)
{
    tree[rt].l = l,tree[rt].r = r;
    tree[rt].val = tree[rt].tag = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
}
void upd(int ql,int qr,int x,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (ql <= l && r <= qr)
    {
        tree[rt].val += x,tree[rt].tag += x;
        return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,x,ls);
    if (qr > mid)
        upd(ql,qr,x,rs);
    push_up(rt);
}
int que(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].val;
    push_down(rt);
    int mid = (l + r) >> 1,res = 0; 
    if (ql <= mid)
        res = max(res,que(ql,qr,ls));
    if (qr > mid)
        res = max(res,que(ql,qr,rs));
    return res;
}
bool operator<(const Klee &x,const Klee &y){return x.pos < y.pos;}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> w;
    build(1,n);
    int u,v,k;
    while (m--)
    {
        cin >> u >> v >> k;
        if(k == -1)
        {
            a.push_back({u,u,v,1});
            a.push_back({v + 1,u,v,-1});
        }
        else
            upd(u,v,k);
    }
    sort(a.begin(),a.end());
    vector<Klee>::iterator p = a.begin();
    for (int i = 1; i <= n; i++)
    {
        while (p != a.end() && i == p->pos)
        {
            upd(p->l,p->r,w * p->f);
            p++;
        }
        cout << (tree[1].val == que(i,i));
    }
    return 0;
}