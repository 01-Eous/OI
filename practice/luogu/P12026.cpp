#include<bits/extc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e5 + 5;
int n,x,y,ans;
pii a[maxn];
int num[maxn];
bool loop[maxn];
vector<int> g[maxn];
void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 1)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (!a[v].second)
                continue;
            int tmp = min(a[u].second,a[v].second);
            a[u].second -= tmp,a[v].second -= tmp;
            ans += tmp,q.push(v);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
        num[i] = a[i].first;
    for (int i = 1; i <= n; i++)
    {
        int p = lower_bound(num + 1,num + n + 1,x - num[i]) - num;
        if (p <= n && num[i] + num[p] == x)
        {
            if (i != p)
                g[i].push_back(p);
            else
                loop[i] = 1;
        }
        p = lower_bound(num + 1,num + n + 1,y - num[i]) - num;
        if (p <= n && num[i] + num[p] == y && x != y)
        {
            if (i != p)
                g[i].push_back(p);
            else
                loop[i] = 1;
        }
    }
    topsort();
    for (int i = 1; i <= n; i++)
        if (loop[i])
            ans += a[i].second >> 1;
    cout << ans;
    return 0;
}