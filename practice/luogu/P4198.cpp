#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int h[maxn];
struct Nahida{int max1,cnt;}tree[maxn << 2];
// x 的斜率严格大于 y
bool cmp(int x,int y){return !h[y] ? h[x] : h[x] * y > h[y] * x;}
int calc(int val,int l,int r,int rt)
{
    if (l == r)
        return cmp(tree[rt].max1,val);
    int mid = (l + r) >> 1;
    if (cmp(tree[ls].max1,val ))
        return calc(val,l,mid,ls) + tree[rt].cnt - tree[ls].cnt;
    else
        return calc(val,mid + 1,r,rs);
}
void build(int l,int r,int rt)
{
    if (l == r)
    {
        tree[rt].max1 = l;
        tree[rt].cnt = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    tree[rt].max1 = cmp(tree[ls].max1,tree[rs].max1) ? tree[ls].max1 : tree[rs].max1;
    tree[rt].cnt = tree[ls].cnt + calc(tree[ls].max1,mid + 1,r,rs);
}
void upd(int x,int l = 1,int r = n,int rt = 1)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (x <= mid)
        upd(x,l,mid,ls);
    else
        upd(x,mid + 1,r,rs);
    tree[rt].max1 = cmp(tree[ls].max1,tree[rs].max1) ? tree[ls].max1 : tree[rs].max1;
    tree[rt].cnt = tree[ls].cnt + calc(tree[ls].max1,mid + 1,r,rs);
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    build(1,n,1);
    int x,y;
    while (m--)
    {
        scanf("%lld%lld",&x,&y);
        h[x] = y,upd(x);
        printf("%lld\n",calc(0,1,n,1));
    }
    return 0;
}