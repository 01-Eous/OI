#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
using namespace std;
typedef array<int,3> iii;
const int maxn = 1e5 + 5;
const int mod = 998244353;
int n,m,ans;
int a[maxn],b[maxn];
priority_queue<iii> q;
inline int cost(int x,int j)// 将 x 分成 j 份
{
    int tmp = x % j;
    return tmp * sq(x / j + 1) + (j - tmp) * sq(x / j);
}
inline void ins(int x,int j)
{
    int tmp = cost(x,j) - cost(x,j + 1);
    q.push({tmp,x,j});
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        a[i] = abs(a[i] - b[i]);
        if (!a[i])
            continue;
        ans = (ans + cost(a[i],1)) % mod;
        ins(a[i],1),m--;
    }
    if (m < 0)
        return cout << "-1",0;
    while (m && !q.empty())
    {
        auto [u,v,w] = q.top();
        q.pop(),m--;
        ans = ((ans - u) % mod + mod) % mod;
        ins(v,w + 1);
    }
    cout << ans;
    return 0;
}