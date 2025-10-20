#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,k;
int a[maxn],b[maxn];
int chk(int mid)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < mid)
            sum += a[i] - mid;
        if (a[i] > mid + k)
            sum += a[i] - (mid + k);
    }
    return sum;
}
void solve()
{
    scanf("%lld%lld",&n,&k);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    sort(a + 1,a + n + 1);
    int l = 1,r = 1e6,mid,res = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(mid) >= 0)
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    memcpy(b,a,sizeof(int) * (n + 5));
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < res)
            b[i] = res,sum += a[i] - res;
        if (a[i] > res + k)
            b[i] = res + k,sum += a[i] - (res + k);
    }
    multiset<int> st;
    for (int i = n; i >= 1; i--)
    {
        if (b[i] == res && sum)
            b[i]++,sum--;
        if (a[i] > res + k && sum)
            b[i]++,sum--;
        st.insert(b[i]);
    }
    while (*st.begin() + k + 1 < *--st.end())
    {
        int tmp = *st.begin();
        st.erase(st.begin());
        st.insert(tmp + 1);
        tmp = *--st.end();
        st.erase(--st.end());
        st.insert(tmp - 1);
    }
    auto it = st.begin();
    for (int i = 1; i <= n; i++)
        b[i] = *it++;
    int ans = 0,dlt = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += b[i] * (b[i] + 1) >> 1;
        dlt += abs(a[i] - b[i]);
    }
    printf("%lld\n",ans + ((dlt >> 1) * k));
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}