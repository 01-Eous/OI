#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e8 + 7;
int n,tp,idx;
int a[maxn],head[maxn],dp1[maxn],dp2[maxn];
struct{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u,int fa)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
        dp1[u] = (dp1[u] + dp1[u] * dp2[v] + dp2[u] * dp1[v] + dp1[v]) % mod;
        dp2[u] = (dp2[u] + dp2[u] * dp2[v] + dp2[v]) % mod; 
    }
    dp1[u] = (dp1[u] + a[u]) % mod,dp2[u]++;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> tp;
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        adde(u,v),adde(v,u);
    }
    for (int i = 1; i <= n; i++)
        a[i] = tp ? i : 1;
    dfs(1,0);
    cout << dp1[1] << '\n';
    return 0;
}