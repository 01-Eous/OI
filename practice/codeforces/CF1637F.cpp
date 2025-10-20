#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,idx,rt,ans;
int h[maxn],head[maxn];
struct{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
int dfs(int u,int fa)
{
    int max1 = 0,max2 = 0;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        max2 = max(max2,dfs(v,u));
        if (max2 > max1)
            swap(max2,max1);
    }
    if (u == rt)
        ans += max(0LL,h[u] - max1) + max(0LL,h[u] - max2);
    else
        ans += max(0LL,h[u] - max1),max1 = max(max1,h[u]);
    return max1;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        if (cin >> h[i]; h[rt] < h[i])
            rt = i;
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        adde(u,v),adde(v,u);
    }
    dfs(rt,0),cout << ans;
    return 0;
}