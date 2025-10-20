#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 5e5 + 5;
int n,q;
bool vis[maxn];
int ans[maxn],pos[maxn],id[maxn];
void solve1()
{
    for (int i = 0; i < n; i++)
    {
        pos[i] = i;
        id[pos[i]] = i;
    }
    int op,x;
    while (q--)
    {
        cin >> op >> x;
        if (op == 1)
        {
            if (~id[x % n])
                ans[id[x % n]]++;
        }
        else if (op == 2)
        {
            fill(id,id + n,-1);
            for (int i = 0; i < n; i++)
            {
                if (vis[i])
                    continue;
                pos[i] = (pos[i] + x) % n;
                id[pos[i]] = i;
            }
        }
        else
        {
            vector<pii> vec[maxn];
            for (int i = 0; i < n; i++)
            {
                if (vis[i])
                    continue;
                int lst = pos[i];
                pos[i] = pos[i] * x % n;
                vec[pos[i]].push_back({(pos[i] - lst + n) % n,i});
            }
            fill(id,id + n,-1);
            for (int i = 0; i < n; i++)
            {
                sort(vec[i].begin(),vec[i].end());
                if (vec[i].empty())
                    id[i] = -1;
                else
                {
                    id[i] = vec[i][0].second;
                    for (int j = 1; j < vec[i].size(); j++)
                    {
                        vis[vec[i][j].second] = 1;
                        pos[vec[i][j].second] = -1;
                    }
                }
            }
        }
    }
}
void solve2()
{
    int offset = 0,op,x;
    while (q--)
    {
        cin >> op >> x;
        if (op == 1)
            ans[(x - offset + n) % n]++;
        else if (op == 2)
            offset = (offset + x) % n;
        else
            return fill(ans,ans + n,0);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    if (n <= 3000)
        solve1();
    else
        solve2();
    for (int i = 1; i < n; i++)
        cout << ans[i] << ' ';
    cout << ans[0] << '\n';
    return 0;
}