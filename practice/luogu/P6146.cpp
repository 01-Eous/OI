#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
int dp[maxn],pw[maxn],buc[maxn << 1];
struct line
{
    int l,r;
    friend bool operator<(const line &x,const line &y){return x.l < y.l;}
}a[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n,pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r;
        buc[a[i].r]++;
        pw[i] = (pw[i - 1] << 1) % mod;
    }
    for (int i = 1; i <= n << 1; i++)
        buc[i] += buc[i - 1];
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
        dp[i] = ((dp[i - 1] << 1) + pw[buc[a[i].l - 1]]) % mod;
    cout << dp[n];
    return 0;
}