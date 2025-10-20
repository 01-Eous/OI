#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define calc(i,j) (w[j] - w[i]) * (h[i] + h[j])
using namespace std;
const int maxn = 3e5 + 5;
int n,m,top;
int st[maxn],tree[maxn];
int w[maxn],h[maxn],ans[maxn];
vector<int> op[maxn];
vector<pair<int,int>> q[maxn];
int lowbit(int x){return x & -x;}
void upd(int i,int x)
{
    for (; i; i -= lowbit(i))
        tree[i] = min(tree[i],x);
}
int que(int i)
{
    int res = inf;
    for (; i <= n; i += lowbit(i))
        res = min(res,tree[i]);
    return res;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld",w + i,h + i);
    for (int i = 1; i <= n; i++)
    {
        while (top && h[st[top]] > h[i])
            top--;
        if (top)
            op[i].push_back(st[top]);
        st[++top] = i;
    }
    top = 0;
    for (int i = n; i >= 1; i--)
    {
        while (top && h[st[top]] > h[i])
            top--;
        if (top)
            op[st[top]].push_back(i);
        st[++top] = i;
    }
    for (int i = 1,l,r; i <= m; i++)
    {
        scanf("%lld%lld",&l,&r);
        q[r].push_back({l,i});
    }
    memset(tree,0x3f,sizeof(int) * (n + 5));
    for (int r = 1; r <= n; r++)
    {
        for (auto x : op[r])
            upd(x,calc(x,r));
        for (auto [l,id] : q[r])
            ans[id] = que(l);
    }
    for (int i = 1; i <= m; i++)
        printf("%lld\n",ans[i]);
    return 0;
}