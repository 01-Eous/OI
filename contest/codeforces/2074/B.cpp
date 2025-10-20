#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    scanf("%d",&n);
    multiset<int,greater<int>> st;
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%d",&x);
        st.insert(x);
    }
    while (st.size() > 1)
    {
        int x = *st.begin();
        st.erase(st.begin());
        int y = *st.begin();
        st.erase(st.begin());
        st.insert(x + y - 1);
    }
    printf("%d\n",*st.begin());
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}