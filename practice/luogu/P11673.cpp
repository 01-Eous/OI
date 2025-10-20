#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n,m;
pair<int,int> que[maxn];
int a[maxn],c[maxn],pos[maxn];
int dp[maxn][3],ans[maxn];
bool cmp(int x,int y){return a[x] < a[y];}
int med(int x,int y,int z){return x + y + z - max({x,y,z}) - min({x,y,z});}
void upd(int rt,int val)
{
    int w[3] = {c[rt],c[rt],c[rt]};
    memset(dp[rt],0x3f,sizeof dp[rt]);
    if (a[rt] < val)
        w[0] = 0;
    else if (a[rt] > val)
        w[2] = 0;
    else
        w[1] = 0;
    if (rs > n)
        return (void)memcpy(dp[rt],w,sizeof w);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int x = med(i,j,k);
                dp[rt][x] = min(dp[rt][x],dp[ls][i] + dp[rs][j] + w[k]);
            }
        }
    }
}
void update(int rt,int val)
{
    while (rt)
    {
        upd(rt,val);
        rt >>= 1;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    iota(pos + 1,pos + n + 1,1);
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
    sort(pos + 1,pos + n + 1,cmp);
    memset(dp,0x3f,sizeof dp);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> que[i].first;
        que[i].second = i;
    }
    sort(que + 1,que + m + 1);
    for (int i = n; i >= 1; i--)
        update(i,0);
    int p1 = 1,p2 = 1;
    for (int i = 1; i <= m; i++)
    {
        auto &[val,id] = que[i];
        while (p1 <= n && a[pos[p1]] < val)
            update(pos[p1++],val);
        while (p2 <= n && a[pos[p2]] <= val)
            update(pos[p2++],val);
        ans[id] = dp[1][1];
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
    return 0;
}