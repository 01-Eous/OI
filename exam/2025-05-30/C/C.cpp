#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 1e6 + 5;
int n,q,tim,idx;
int ans[maxn];
vector<array<int,3>> opt[maxn],que[maxn];
struct Nahida{int val,tim;}tree[maxn << 2];
void upd(int pos,int val,int tim,int l = 1,int r = q,int rt = 1)
{
    tree[rt].val += val;
    if (l == r)
    {
        tree[rt].tim = tim;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,val,tim,l,mid,ls);
    else
        upd(pos,val,tim,mid + 1,r,rs);
}
int que_kth(int k,int tim,int l = 1,int r = q,int rt = 1)
{
    if(k > tree[rt].val)
        return 0;
    if (l == r)
        return ((tree[rt].tim <= tim) ? l : 0);
    int mid = (l + r) >> 1,tmp = tree[ls].val;
    if (k <= tmp)
        return que_kth(k,tim,l,mid,ls);
    else
        return que_kth(k - tmp,tim,mid + 1,r,rs);
}
signed main()
{
    scanf("%lld%lld",&n,&q);
    int op,l,r,x;
    for (int i = 1; i <= q; i++)
    {
        scanf("%lld",&op);
        if (op == 1)
        {
            tim++;
            scanf("%lld%lld%lld",&l,&r,&x);
            opt[l].push_back({i,x,tim});
            opt[r + 1].push_back({i,-x,tim});
        }
        else
        {
            scanf("%lld%lld",&l,&x);
            que[l].push_back({++idx,x,tim});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto [pos,val,time] : opt[i])
            upd(pos,val,time);
        for (auto [id,k,time] : que[i])
            ans[id] = que_kth(k,time);
    }
    for (int i = 1; i <= idx; i++)
        printf("%lld\n",ans[i]);
    return 0;
}