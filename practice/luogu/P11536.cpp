#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
const int maxn = 5e5 + 5;
int n,m,q;
bool ans[maxn];
vector<pii> que[maxn];
vector<int> line[maxn];
struct
{
    int min1,min2,tag;
    void tag_down(int x){min1 = tag = x;}
}tree[maxn << 2];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
#define ls rt << 1
#define rs rt << 1 | 1
void push_up(int rt)
{
    tree[rt].min1 = min(tree[ls].min1,tree[rs].min1);
    if (tree[ls].min1 < tree[rs].min1)
    {
        tree[rt].min1 = tree[ls].min1;
        tree[rt].min2 = min(tree[ls].min2,tree[rs].min1);
    }
    else if (tree[ls].min1 > tree[rs].min1)
    {
        tree[rt].min1 = tree[rs].min1;
        tree[rt].min2 = min(tree[rs].min2,tree[ls].min1);
    }
    else
    {
        tree[rt].min1 = tree[ls].min1;
        tree[rt].min2 = min(tree[ls].min2,tree[rs].min2);
    }
}
void push_down(int rt)
{
    int &tag = tree[rt].tag;
    if (!~tag)
        return;
    bool f1 = 0,f2 = 0;
    if (tree[ls].min1 <= tree[rs].min1)
        f1 = 1;
    if (tree[ls].min1 >= tree[rs].min1)
        f2 = 1;
    if (f1)
        tree[ls].tag_down(tag);
    if (f2)
        tree[rs].tag_down(tag);
    tag = -1;
}
void build(int l,int r,int rt)
{
    tree[rt].tag = -1;
    if (l == r)
    {
        tree[rt].min1 = l + 1;
        tree[rt].min2 = inf;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void update(int ql,int qr,int x,int xx,int l = 1,int r = n,int rt = 1)
{
    if (tree[rt].min1 > x)
        return;
    if (ql <= l && r <= qr)
    {
        if (tree[rt].min2 > x)
            return tree[rt].tag_down(xx);
        int mid = (l + r) >> 1;
        push_down(rt);
        update(ql,qr,x,xx,l,mid,ls);
        update(ql,qr,x,xx,mid + 1,r,rs);
        return push_up(rt);
    }
    int mid = (l + r) >> 1;
    push_down(rt);
    if (ql <= mid)
        update(ql,qr,x,xx,l,mid,ls);
    if (qr > mid)
        update(ql,qr,x,xx,mid + 1,r,rs);
    push_up(rt);
}
int query(int pos,int l = 1,int r = n,int rt = 1)
{
    if (l == r)
        return tree[rt].min1;
    int mid = (l + r) >> 1;
    push_down(rt);
    if (pos <= mid)
        return query(pos,l,mid,ls);
    else
        return query(pos,mid + 1,r,rs);
}
#undef ls
#undef rs
signed main()
{
    n = read(),m = read(),q = read();
    for (int i = 1,l,r; i <= m; i++)
    {
        l = read(),r = read();
        line[l].push_back(r);
    }
    for (int i = 1,l,r; i <= q; i++)
    {
        l = read(),r = read();
        que[l].push_back({r,i});
    }
    build(1,n,1);
    for (int l = n; l >= 1; l--)
    {
        for (auto r : line[l])
            update(r,n,r + 1,l);
        for (auto [r,id] : que[l])
            ans[id] = query(r) == l;
    }
    for (int i = 1; i <= q; i++)
        puts(ans[i] ? "YES" : "NO");
    return 0;
}