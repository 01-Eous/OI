#include <bits/extc++.h>
using namespace std;

typedef long long ll;
constexpr int MAXN = 2e5 + 5;
int T,n,a[MAXN],b[MAXN],ord[MAXN];
vector<int> fac[MAXN];
inline void Solve()
{
    cin >> n;
    vector<int> cnt(MAXN,0);
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        for(int x : fac[a[i]])
        {
            if(cnt[x])
                ans = 0;
            ++cnt[x];
        }
    }
    for(int i = 1;i <= n;i++)
        cin >> b[i];
    for(int i = 1;i <= n;i++)
    {
        for(int x : fac[a[i]])
            --cnt[x];
        for(int x : fac[a[i] + 1])
        {
            if(cnt[x])
                ans = min(ans,(ll)b[i]);
        }
        for(int x : fac[a[i]])
            ++cnt[x];
    }
    iota(ord + 1,ord + n + 1,1);
    sort(ord + 1,ord + n + 1,[&](int A,int B){return b[A] < b[B];});
    ans = min(ans,(ll)(b[ord[1]] + b[ord[2]]));
    vector<int> rec;
    for(int i = 2;i <= n;i++)
    {
        for(int x : fac[a[ord[i]]])
            rec.emplace_back(x);
    }
    for(int x : rec)
    {
        int val = x - (a[ord[1]] % x);
        if(val == x)
            val = 0;
        ans = min(ans,1ll * val * b[ord[1]]);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(int d = 2,V = 2e5 + 1;d <= V;d++)
    {
        if(!fac[d].empty())
            continue;
        for(int T = d;T <= V;T += d)
            fac[T].emplace_back(d);
    }
    cin >> T;
    while(T--)
       Solve();
}