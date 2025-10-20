#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 998244353;
int n;
void solve()
{
    cin >> n;
    vector<int> p(n + 5),dp1(n + 5),dp2(n + 5),sum(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    stack<int> st;
    dp2[0] = sum[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && p[st.top()] > p[i])
            st.pop();
        int j = st.empty() ? 0 : st.top();
        if (j)
            dp1[i] = (dp1[j] + dp2[j]) % mod;
        dp2[i] = ((dp1[j] + sum[i - 1] - (j ? sum[j - 1] : 0)) % mod + mod) % mod;
        sum[i] = (sum[i - 1] + dp2[i]) % mod;
        st.push(i);
    }
    cout << (dp1[n] + dp2[n]) % mod << '\n';
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