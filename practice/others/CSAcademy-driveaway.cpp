#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e5 + 5;
int n,k;
bool vis[maxn];
int a[maxn],pre[maxn],nxt[maxn],val[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    priority_queue<pii> q;
    for (int i = 1; i < n; i++)
    {
        val[i] = min(k,a[i] + a[i + 1]);
        q.push({val[i],i});
        pre[i] = i - 1,nxt[i] = i + 1;
    }
    val[0] = val[n] = ~inf;
    for (int i = 1; i <= (n >> 1); i++)
    {
        while (vis[q.top().second])
            q.pop();
        auto [dlt,pos] = q.top();
        q.pop();
        ans -= dlt;
        vis[pre[pos]] = vis[nxt[pos]] = 1;
        val[pos] = val[pre[pos]] + val[nxt[pos]] - dlt;
        q.push({val[pos],pos});
        nxt[pos] = nxt[nxt[pos]],pre[pos] = pre[pre[pos]];
        pre[nxt[pos]] = nxt[pre[pos]] = pos;
        cout << ans << '\n';
    }
    return 0;
}