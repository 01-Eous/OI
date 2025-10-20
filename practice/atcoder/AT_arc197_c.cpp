#include<bits/extc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 3e6 + 5;
int q;
int tree[maxn << 2];
bool vis[maxn],del[maxn];
void push_up(int rt){tree[rt] = tree[ls] + tree[rs];}
void build(int l,int r,int rt)
{
    if (l == r)
    {
        tree[rt] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int x,int l = 1,int r = 3e6,int rt = 1)
{
    if (l == r)
    {
        tree[rt] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        upd(x,l,mid,ls);
    else
        upd(x,mid + 1,r,rs);
    push_up(rt);
}
int que(int k,int l = 1,int r = 3e6,int rt = 1)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1,tmp = tree[ls];
    if (k <= tmp)
        return que(k,l,mid,ls);
    else
        return que(k - tmp,mid + 1,r,rs);
}
signed main()
{
    scanf("%d",&q);
    build(1,3e6,1);
    int x,k;
    while (q--)
    {
        scanf("%d%d",&x,&k);
        if (x > 3e6 || vis[x])
            goto Nahida;
        vis[x] = 1;
        for (int i = x; i <= 3e6; i += x)
            if (!del[i])
                upd(i),del[i] = 1;
        Nahida:
        printf("%d\n",que(k));
    }
    return 0;
}