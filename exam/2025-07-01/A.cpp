#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,m;
multiset<int> st;
void solve()
{
    scanf("%lld%lld",&n,&m);
    st.clear();
    int ans = 0;
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%lld",&x);
        ans += x;
        st.insert(x);
    }
    int lst = 0;
    while (!st.empty())
    {
        if (*st.begin() > m - lst)
        {
            ans++;
            lst = 0;
            continue;
        }
        auto it = --st.upper_bound(m - lst);
        lst = *it;
        st.erase(it);
    }
    printf("%lld\n",ans + 1);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}