#include<bits/extc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#define int long long
using namespace std;
typedef unsigned long long ull;
random_device seed;
mt19937_64 rnd(seed());
const int maxn = 1e6  + 5;
int n,m;
ull hsh[maxn];
int a[maxn],cnt[maxn];
__gnu_pbds::gp_hash_table<ull,int> mp;
void read(int &x)
{
    int f = 1; x = 0;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
ull get_rnd(int l,int r){return rnd() % (r - l + 1) + l;}
void solve()
{
    read(n),read(m);
    hsh[m] = 0;
    for (int i = 1; i < m; i++)
    {
        hsh[i] = get_rnd(1,1145141919810);
        hsh[m] -= hsh[i];
    }
    mp.clear();
    mp[0] = 1;
    int ans = 0;
    ull hs = 0;
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        hs += hsh[a[i]];
        ans += mp[hs]++;
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