#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e7 + 5;
const int mod = 998244353;
int n,idx;
bool vis[maxn];
int pr[maxn],phi[maxn],fi[maxn];
void init()
{
    fi[1] = phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fi[i] = (fi[i - 1] + fi[i - 2]) % mod;
        if (!vis[i])
        {
            pr[++idx] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0)
            {
                phi[i * pr[j]] = phi[i] * pr[j];
                break;
            }
            phi[i * pr[j]] = phi[i] * phi[pr[j]];
        }
    }
    for (int i = 1; i <= n; i++)
        phi[i] = (phi[i] + phi[i - 1]) % mod;
}
int f(int x){return ((phi[n / x] << 1) + mod - 1) % mod;}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n,init();
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + fi[i] * f(i)) % mod;
    cout << ans << '\n';
    return 0;
}