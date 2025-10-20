#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1e5 + 5;
int n;
int in[maxn];
vector<int>g[maxn],ans;
inline void topsort()
{
    queue<int>q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
            ans.push_back(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            in[v]--;
            if (in[v] == 0)
            {
                q.push(v);
                ans.push_back(v);
            }
        }
    }
}
inline void solve()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        g[i].clear();
    fill(in + 1,in + n + 1,0);
    char ch;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ch;
            if (i < j)
            {
                if (ch == '1')
                {
                    in[j]++;
                    g[i].push_back(j);
                }
                else
                {
                    in[i]++;
                    g[j].push_back(i);
                }
            }
        }
    }
    ans.clear();
    topsort();
    for (auto i : ans)
        printf("%d ",i);
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}