#include<bits/extc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 5e5 + 5;
int n,q,cnt;
int a[maxn],tree[maxn << 2];
void push_up(int rt){tree[rt] = __gcd(tree[ls],tree[rs]);}
void build(int l,int r,int rt)
{
    if (l == r)
    {
        tree[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int pos,int x,int l = 1,int r = n,int rt = 1)
{
    if (l == r)
    {
        tree[rt] = x;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,x,l,mid,ls);
    else
        upd(pos,x,mid + 1,r,rs);
    push_up(rt);
}
void que(int ql,int qr,int x,int l = 1,int r = n,int rt = 1)
{
    if (cnt > 1)
        return;
    if (l == r)
    {
        cnt++;
        return;
    }
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid && tree[ls] % x)
        que(ql,qr,x,l,mid,ls);
    if (qr > mid && tree[rs] % x)
        que(ql,qr,x,mid + 1,r,rs);
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    build(1,n,1);
    scanf("%d",&q);
    int op,l,r,x;
    while (q--)
    {
        scanf("%d",&op);
        if (op == 1)
        {
            scanf("%d%d%d",&l,&r,&x);
            cnt = 0,que(l,r,x);
            puts(cnt <= 1 ? "YES" : "NO");
        }
        else
            scanf("%d%d",&l,&x),upd(l,x);
    }
    return 0;
}