#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 5e5 + 5;
int n,m,nn;
int a[maxn],suf[maxn];
multiset<int> st;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    st.insert(0);
    for (int i = n; i >= 1; i--)
    {
        suf[i] = suf[i + 1] + a[i];
        st.insert(suf[i]);
    }
    int sum = 0,ans = -inf;
    set<int>::iterator it;
    for (int i = 1; i <= n; i++)
    {
        st.erase(st.find(suf[i]));
        it = st.lower_bound(m - sum);
        if (it != st.end())
            ans = max(ans,suf[1] - sum - *it);
        sum += a[i];
    }
    if (ans != -inf)
        cout << ans << '\n';
    else
        cout << "NO\n";
    fprintf(stderr,"%.3lf\n",1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}