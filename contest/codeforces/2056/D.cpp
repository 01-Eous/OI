#include<bits/extc++.h>
using namespace std;
typedef long long ll;
int n;
template<typename type>
inline void read(type &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
inline void solve()
{
    read(n);
    vector<int>a(n + 5,0);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        a[i]--;
    }
    ll ans = 1LL * n * (n + 1) >> 1;
    for (int k = 0; k < 10; k++)
    {
        vector<int>pre(n + 5,0);
        for (int i = 1; i <= n; i++)
            pre[i + 1] = pre[i] + (a[i] >= k ? 1 : -1);
        map<int,int>mp;
        int l = 1,r = 1;
        while (r <= n)
        {
            if (a[r] == k)
                while (l <= r)
                    mp[pre[l++]]++;
            ans -= mp[pre[++r]];
        }
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    read(t);
    while (t--)
        solve();
    return 0;
}