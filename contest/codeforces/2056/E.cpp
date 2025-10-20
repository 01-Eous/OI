#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int maxn = 2e5 + 5;
int n,m;
int fac[maxn],inv[maxn];
struct Nahida{int l,r,len;};
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
inline bool operator<(Nahida x,Nahida y){return x.l ^ y.l ? x.l < y.l : x.r > y.r;}
inline int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
inline void init(int up = 2e5)
{
    fac[0] = 1;
    for (int i = 1; i <= up; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[up] = binpow(fac[up],mod - 2);
    for (int i = up - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
inline int c(int n,int m){return n < 0 || m < 0 || n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
inline int cata(int n){return n < 0 ? 1 : (c(n * 2,n) - c(n * 2,n - 1) + mod) % mod;}
inline void solve()
{
    read(n),read(m);
    vector<Nahida>a;
    bool fl = 0;
    for (int i = 1,l,r,len; i <= m; i++)
    {
        read(l),read(r);
        len = r - (--l);
        fl |= (len == n);
        a.push_back({l,r,len});
    }
    if (!fl)
        a.push_back({0,n,n});
    sort(a.begin(),a.end());
    stack<vector<Nahida>::iterator>st;
    for (auto i = a.begin(); i != a.end(); i++)
    {
        auto [l,r,len] = *i;
        while (!st.empty() && l >= st.top()->r)
            st.pop();
        if (!st.empty())
            st.top()->len -= r - l - 1;
        st.push(i);
    }
    int ans = 1;
    for (auto [l,r,len] : a)
        ans = ans * cata(len - 1) % mod;
    printf("%lld\n",ans);
}
signed main()
{
    init();
    int t;
    read(t);
    while (t--)
        solve();
    return 0;
}