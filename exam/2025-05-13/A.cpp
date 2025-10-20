#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int n,m,sum,cnt,siz;
char s[maxn];
int pw[maxn],l[maxn],r[maxn];
bool a[maxn],vis[maxn],way[maxn];
vector<pair<int,int>> g[maxn];
void dfs(int u,int pre)
{
    vis[u] = 1,sum += a[u],siz++;
    cnt += g[u].size();
    for (auto [v,id] : g[u])
        if (!vis[v])
            dfs(v,id);
    if (a[u])
    {
        if (!pre)
        {
            printf("0\nNO");
            exit(0);
        }
        way[pre] = 1;
        a[l[pre]] ^= 1;
        a[r[pre]] ^= 1;
    }
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = (pw[i - 1] << 1) % mod;
    scanf("%s",s + 1);
    for (int i = 1; i <= n; i++)
        a[i] = s[i] == '1';
    scanf("%s",s + 1);
    for (int i = 1; i <= n; i++)
        a[i] ^= s[i] == '1';
    for (int i = n + 1; i >= 1; i--)
        a[i] ^= a[i - 1];
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld",l + i,r + i);
        r[i]++;
        g[l[i]].push_back({r[i],i});
        g[r[i]].push_back({l[i],i});
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        sum = cnt = siz = 0;
        dfs(i,0);
        ans += (cnt >> 1) - siz + 1;
    }
    printf("%lld\nYES\n",pw[ans]);
    for (int i = 1; i <= m; i++)
        putchar('0' + way[i]);
    return 0;
}