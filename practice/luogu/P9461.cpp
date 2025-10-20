#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e6 + 5;
const int mod = 998244353,inv2 = 499122177;
int n,m,sumx,sumy;
pii a[maxn];
bool vis[maxn];
int fa[maxn],siz[maxn],sum[maxn];
int calc(int x){return x * (x + 1) % mod * inv2 % mod;}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void un(int u,int v)
{
    if (siz[u] > siz[v])
        swap(u,v);
    fa[u] = v;
    siz[v] += siz[u];
    sum[v] = (sum[v] + sum[u]) % mod;
}
void mg(int u,int v)
{
    u = find(u),v = find(v);
    sumx = (sumx + siz[u] * sum[v]) % mod;
    sumy = ((sumy - calc(siz[u]) - calc(siz[v])) % mod + calc(siz[u] + siz[v]) + mod) % mod;
    un(u,v);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    iota(fa + 1,fa + n + 1,1);
    fill(siz + 1,siz + n + 1,1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        m = (m + a[i].first) % mod;
        a[i].second = i;
    }
    m = calc(m);
    sort(a + 1,a + n + 1,greater<>());
    int p = 1,ans = 0;
    for (int i = 1e6; i > 1; i--)
    {
        while (p <= n && a[p].first == i)
        {
            auto [x,id] = a[p];
            vis[id] = 1,sum[id] = x;
            sumx = (sumx + x) % mod;
            sumy = (sumy + 1) % mod;
            if (vis[id - 1])
                mg(id - 1,id);
            if (vis[id + 1])
                mg(id,id + 1);
            p++;
        }
        int tmp = (sumx - (i - 1) * sumy % mod + mod) % mod;
        m = (m - tmp + mod) % mod;
        ans = (ans + tmp * i) % mod;
    }
    cout << (ans + m) % mod << '\n';
    return 0;
}