#include<bits/extc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 5e5 + 5;
int n,m,d;
int a[maxn],tree[maxn << 2];
void upd(int pos,int x,int l = 1,int r = m,int rt = 1)
{
    if (l == r)
    {
        tree[rt] = max(tree[rt],x);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,x,l,mid,ls);
    else
        upd(pos,x,mid + 1,r,rs);
    tree[rt] = max(tree[ls],tree[rs]);
}
int que(int ql,int qr,int l = 1,int r = m,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt];
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res = max(res,que(ql,qr,l,mid,ls));
    if (qr > mid)
        res = max(res,que(ql,qr,mid + 1,r,rs));
    return res;
}
signed main()
{
    scanf("%d%d",&n,&d);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",a + i);
        m = max(m,a[i]);
    }
    for (int i = 1; i <= n; i++)
        upd(a[i],que(max(1,a[i] - d),min(m,a[i] + d)) + 1);
    printf("%d",tree[1]);
    return 0;
}