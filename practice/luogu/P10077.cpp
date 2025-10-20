#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 5e5 + 5;
int _,n,cnt;
int tree[maxn << 2];
void build(int l,int r,int rt)
{
    if (l == r)
    {
        scanf("%d",tree + rt);
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    tree[rt] = min(tree[ls],tree[rs]);
}
void upd(int l,int r,int rt)
{
    if (l == r)
    {
        cnt++;
        tree[rt] = inf;
        return;
    }
    int mid = (l + r) >> 1;
    if (tree[ls] <= cnt)
        upd(l,mid,ls);
    if (tree[rs] <= cnt)
        upd(mid + 1,r,rs);
    tree[rt] = min(tree[ls],tree[rs]);
}
signed main()
{
    scanf("%d%d",&_,&n);
    build(1,n,1);
    for (int i = 1; i <= n; i++)
        if (upd(1,n,1); tree[1] == inf)
            return printf("%d",i),0;
    printf("-1");
    return 0;
}