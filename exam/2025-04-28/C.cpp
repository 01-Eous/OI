#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3fLL
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1 << 21,stdin),p1 == p2) ? EOF : *p1++)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx","avx2","sse")
using namespace std;
const int maxn = 1e6 + 5;
char buf[1 << 23],*p1 = buf,*p2 = buf;
int n,m;
int h[maxn],num[maxn];
int a[maxn],b[maxn],op[maxn],d[maxn];
multiset<int> st[maxn][4];
struct Nahida{int ans,val[4];}tree[maxn << 2];
void read(int &x)
{
    x = 0;
    char f = 1,ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    x *= f;
}
void push_up(int rt)
{
    for (int i = 0; i < 4; i++)
        tree[rt].val[i] = min(tree[ls].val[i],tree[rs].val[i]);
    tree[rt].ans = min(inf,min(
        tree[rs].val[0] + tree[ls].val[2],
        tree[ls].val[1] + tree[rs].val[3]
    ));
    tree[rt].ans = min(tree[rt].ans,min(tree[ls].ans,tree[rs].ans));
}
void build(int l,int r,int rt)
{
    tree[rt].ans = inf;
    if (l == r)
    {
        #pragma GCC unroll 8
        for (int i = 0; i < 4; i++)
        {
            st[l][i].insert(inf);
            tree[rt].val[i] = inf;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int id,int x,int l = 1,int r = n,int rt = 1)
{
    if (l == r)
    {
        int p = d[id] ? 2 : 0;
        if (op[id])
        {
            st[l][p + 0].insert(a[id]);
            st[l][p + 1].insert(b[id]);
        }
        else
        {
            st[l][p + 0].erase(st[l][p + 0].find(a[id]));
            st[l][p + 1].erase(st[l][p + 1].find(b[id]));
        }
        #pragma GCC unroll 8
        for (int i = 0; i < 4; i++)
            tree[rt].val[i] = *st[l][i].begin();
        tree[rt].ans = min({inf,tree[rt].val[0] + tree[rt].val[2],tree[rt].val[1] + tree[rt].val[3]});
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        upd(id,x,l,mid,ls);
    else
        upd(id,x,mid + 1,r,rs);
    push_up(rt);
}
signed main()
{
    read(m);
    #pragma GCC unroll 8
    for (int i = 1; i <= m; i++)
    {
        read(op[i]),read(d[i]),read(a[i]),read(b[i]);
        num[i] = h[i] = !d[i] ? (a[i] - b[i]) : (b[i] - a[i]);
    }
    sort(num + 1,num + m + 1);
    n = unique(num + 1,num + m + 1) - num - 1;
    build(1,n,1);
    for (int i = 1; i <= m; i++)
    {
        h[i] = lower_bound(num + 1,num + n + 1,h[i]) - num;
        upd(i,h[i]);
        if (tree[1].ans >= inf)
            puts("-1");
        else
            printf("%lld\n",tree[1].ans);
    }
    return 0;
}