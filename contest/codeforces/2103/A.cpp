#include<bits/extc++.h>
using namespace std;
int n;
set<int> st;
void solve()
{
    scanf("%d",&n);
    st.clear();
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%d",&x);
        st.insert(x);
    }
    printf("%llu\n",st.size());
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}