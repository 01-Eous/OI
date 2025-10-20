#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
#define chkmin(x,y) (x = min(x,y))
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e5 + 5;
int n;
int a[maxn];
vector<pii> vec;
struct Nahida
{
    int l,r;
    int dp[2][2];
}tree[maxn << 2];
void push_up(int rt)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            tree[rt].dp[i][j] = inf;
            for (int k = 0; k < 2; k++)
                chkmin(tree[rt].dp[i][j],max(tree[ls].dp[i][k],tree[rs].dp[k][j]));
        }
    }
}
void build(int l,int r,int rt)
{
    tree[rt].l = l,tree[rt].r = r;
    if (l == r)
    {
        tree[rt].dp[0][0] = a[l];
        if (1 < l)
            tree[rt].dp[1][0] = a[l - 1] + a[l];
        else
            tree[rt].dp[1][0] = inf;
        if (r < n)
            tree[rt].dp[0][1] = a[r] + a[r + 1];
        else
            tree[rt].dp[0][1] = inf;
        tree[rt].dp[1][1] = inf;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int x,int i,int j,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (l == r)
    {
        tree[rt].dp[i][j] = inf;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        upd(x,i,j,ls);
    else
        upd(x,i,j,rs);
    push_up(rt);
}
void solve()
{
    cin >> n;
    vec.clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vec.push_back({a[i],i});
    }
    for (int i = 1; i < n; i++)
        vec.push_back({a[i] + a[i + 1],i + n});
    sort(vec.begin(),vec.end());
    build(1,n,1);
    int ans = inf;
    for (auto [val,id] : vec)
    {
        ans = min(ans,tree[1].dp[0][0] - val);
        if (id <= n)
            upd(id,0,0);
        else
        {
            upd(id - n,0,1);
            upd(id - n + 1,1,0);
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}