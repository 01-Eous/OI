#include<bits/extc++.h>
#define int long long
#define calc(u) (ban[u][1] + ban[u][2] + ban[u][3])
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e5 + 5;
int n,idx;
bool ban[maxn][5];
int head[maxn],col[maxn];
struct{int v,nxt;}e[maxn << 2];
stack<pii,vector<pii>> stk;
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u)
{
    for (int k = 1; k <= 3; k++)
    {
        if (ban[u][k])
            continue;
        col[u] = k;
        for (int i = head[u]; i; i = e[i].nxt)
            ban[e[i].v][k] = 1;
        for (int i = head[u]; i; i = e[i].nxt)
            if (int v = e[i].v; !col[v] && calc(v) == 2)
                dfs(v);
        for (int i = head[u]; i; i = e[i].nxt)
            if (int v = e[i].v; !col[v])
                dfs(v);
        break;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1,x,y; i <= n; i++)
    {
        cin >> x >> y;
        while (x)
        {
            auto &[fi,se] = stk.top();
            int tmp = min(x,fi);
            x -= tmp,fi -= tmp;
            adde(i,se),adde(se,i);
            if (!fi)
                stk.pop();
        }
        if (y)
            stk.push({y,i});
    }
    for (int i = 1; i <= n; i++)
        if (!col[i])
            col[i] = 1,dfs(i);
    cout << *max_element(col + 1,col + n + 1) << '\n';
    for (int i = 1; i <= n; i++)
        cout << col[i] << " \n"[i == n];
    return 0;
}