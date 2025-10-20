#include<bits/extc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n;
pii a[maxn];
int tree[maxn],dp[maxn];
inline int lowbit(const int &x){return x & -x;}
inline void upd(int i,const int &x)
{
    for (i++; i <= n + 5; i += lowbit(i))
        tree[i] = (tree[i] + x) % mod;
}
inline int que(int i)
{
    int res = 0;
    for (i++; i; i -= lowbit(i))
        res = (res + tree[i]) % mod;
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second;
    sort(a + 1,a + n + 1);
    int ans = 1;
    upd(0,1);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = que(a[i].second);
        upd(a[i].second,dp[i]);
        ans = (ans + dp[i]) % mod;
    }
    cout << ans;
    return 0;
}