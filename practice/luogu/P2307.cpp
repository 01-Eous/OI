#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n = 1e5;
int fa[maxn];
vector<int> vec;
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void solve()
{
    iota(fa + 1,fa + n + 1,1);
    vec.clear();
    bool fl = 1;
    int u,v,x;
    while (1)
    {
        cin >> u >> v;
        if (!~u && !~v)
            exit(0);
        else if (!u && !v)
            goto Hoshino;
        vec.push_back(u);
        vec.push_back(v);
        u = find(u),v = find(v);
        if (u == v)
            fl = 0;
        else
            fa[u] = v;
    }
    Hoshino:
    x = find(vec[0]);
    for (int i = 1; i < vec.size(); i++)
        if (find(vec[i]) != x)
            return (void)(cout << "0\n");
    cout << fl << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (n)
        solve();
    return 0;
}