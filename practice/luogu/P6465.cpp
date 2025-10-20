#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n,m,idx;
int a[maxn],l[maxn],r[maxn];
vector<int> pos[maxn];
unordered_set<int> st;
int sum(int x){return (x + 1) * x >> 1;}
void solve()
{
    scanf("%lld%lld",&n,&m);
    m = max(m,2LL);
    l[idx = 1] = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        if (a[i] == a[i - 1])
            l[++idx] = i;
        r[idx] = i;
    }
    int ans = 0;
    for (int i = 1; i <= idx; i++)
    {
        int len = r[i] - l[i] + 1;
        if (len < m)
            continue;
        ans += sum(len - m + 1);
        for (int j = l[i]; j <= r[i]; j++)
        {
            st.insert(a[j]);
            pos[a[j]].push_back(j);
        }
        for (auto x : st)
        {
            for (auto it = pos[x].begin(); it != pos[x].end(); it++)
                ans -= pos[x].end() - lower_bound(pos[x].begin(),pos[x].end(),*it + m - 1);
            pos[x].clear();
        }
        st.clear();
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}