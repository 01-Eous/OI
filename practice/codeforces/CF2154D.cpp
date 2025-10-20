#include<bits/extc++.h>
using namespace std;
using pii = pair<int,int>;
const int maxn = 2e5 + 5;
int n,idx;
bool col[maxn];
int son[maxn],fa[maxn],head[maxn];
vector<pii> ans;
struct{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u,int pre)
{
    fa[u] = pre,col[u] = col[pre] ^ 1;
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != pre)
            son[u]++,dfs(v,u);
}
void solve()
{
    cin >> n;
    ans.clear();
    memset(son,0,sizeof(int) * (n + 5));
    memset(head,0,sizeof(int) * (n + 5));
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        adde(u,v),adde(v,u);
    }
    dfs(n,0);
    queue<int> q[2];
    for (int i = 1; i <= n; i++)
        if (!son[i])
            q[col[i]].push(i);
    bool cur = col[1];
    for (int i = 1; i < n; i++)
    {
        bool nxt = cur ^ 1;
        if (q[nxt].empty())
        {
            ans.push_back({1,0});
            nxt ^= 1;
        }
        int tmp = q[nxt].back();
        q[nxt].pop();
        ans.push_back({2,tmp});
        if (!--son[fa[tmp]])
            q[col[fa[tmp]]].push(fa[tmp]);
        ans.push_back({1,0});
        cur = nxt;
    }
    cout << ans.size() << '\n';
    for (auto [x,y] : ans)
    {
        if (x == 1)
            cout << "1\n";
        else
            cout << "2 " << y << '\n';
    }
    cout << '\n';
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