#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    scanf("%d",&n);
    int l,r;
    multiset<int> st;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d",&l,&r);
        auto it = st.upper_bound(r);
        if (it != st.end())
            st.erase(it);
        st.insert(l);
        printf("%llu ",st.size());
    }
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}