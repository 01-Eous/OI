#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
int n,s1,s2,m1,m2;
int u[1005],v[1005];
bool b[1005];
vector<int>g1[1005],g2[1005];
void solve()
{
    cin >> n >> s1 >> s2;
    fill(b + 1,b + n + 1,0);
    fill(g1 + 1,g1 + n + 1,vector<int>());
    fill(g2 + 1,g2 + n + 1,vector<int>());
    cin >> m1;
    for (int i = 1; i <= m1; i++)
    {
        cin >> u[i] >> v[i];
        if (u[i] > v[i])
            swap(u[i],v[i]);
        g1[u[i]].push_back(v[i]);
        g1[v[i]].push_back(u[i]);
    }
    cin >> m2;
    for (int i = 1,x,y; i <= m2; i++)
    {
        cin >> x >> y;
        if (x > y)
            swap(x,y);
        bool flag = 0;
        for (int j = 1; j <= m1; j++)
        {
            if (x == u[j] && y == v[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            b[x] = b[y] = 1;
        g2[x].push_back(y);
        g2[y].push_back(x);
    }
    vector<vector<int>>dis(n + 5,vector<int>(n + 5,inf));
    set<pair<int,pii>>st;
    dis[s1][s2] = 0;
    st.insert({0,{s1,s2}});
    while (!st.empty())
    {
        auto [u1,u2] = st.begin()->second;
        st.erase(st.begin());
        for (auto v1 : g1[u1])
        {
            for (auto v2 : g2[u2])
            {
                int w = abs(v1 - v2);
                if (dis[v1][v2] > dis[u1][u2] + w)
                {
                    st.erase({dis[v1][v2],{v1,v2}});
                    dis[v1][v2] = dis[u1][u2] + w;
                    st.insert({dis[v1][v2],{v1,v2}});
                }
            }
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; i++)
        if (b[i])
            ans = min(ans,dis[i][i]);
    cout << (ans ^ inf ? ans : -1) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}