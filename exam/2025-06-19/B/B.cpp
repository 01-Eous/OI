#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using pii = pair<int,int>;
const int maxn = 3e5 + 5;
int n,m,max1;
int a[2005],ans[maxn];
struct query{int l,w,id;};
set<pii> st;
vector<query> q[2005];
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = 1,l,r,w; i <= m; i++)
    {
        scanf("%lld%lld%lld",&l,&r,&w);
        max1 = max(max1,w);
        q[r].push_back({l,w,i});
    }
    st.insert({0,inf});
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = i; j >= 1; j--)
        {
            sum += a[j];
            if (sum > max1)
                break;
            st.insert({sum,j});
        }
        for (auto [l,w,id] : q[i])
        {
            auto it = --st.upper_bound({w,inf});
            while (it != st.begin() && it->second < l)
                it--;
            if (it->second >= l)
                ans[id] = it->first;
        }
    }
    for (int i = 1; i <= m; i++)
        printf("%lld\n",ans[i]);
    return 0;
}