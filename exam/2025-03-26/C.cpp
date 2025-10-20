#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int maxn = 1 << 6 | 5;
int n,m;
string l,r;
int id[maxn];
bool vis[maxn];
vector<int> g[maxn];
struct mat
{
    int a[25][25];
    mat(bool op = 0)
    {
        memset(a,0,sizeof a);
        if (!op)
            return;
        for (int i = 1; i <= n; i++)
            a[i][i] = 1;
    }
    friend mat operator*(const mat &x,const mat &y)
    {
        mat res;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j] % mod) % mod;
        return res;
    }
}ans,base;
mat binpow(mat x,string str)
{
    for (auto &ch : str)
        ch ^= 48;
    deque<bool> y;
    int idx = 0;
    while (idx < str.size())
    {
        while (!str[idx])
            idx++;
        for (int i = idx; i < str.size(); i++)
        {
            if (i == str.size() - 1)
            {
                y.push_back(str[i] & 1);
                str[i] >>= 1;
                break;
            }
            else
            {
                str[i + 1] += (str[i] & 1) * 10;
                str[i] >>= 1;
            }
        }
    }
    mat res(1);
    while (!y.empty())
    {
        if (y.front())
            res = res * x;
        x = x * x;
        y.pop_front();
    }
    return res;
}
bool chk(int sta)
{
    int len = 0;
    for (int i = 0; i < m; i++)
    {
        if (sta & (1 << i))
        {
            if (len & 1)
                return 0;
            len = 0;
        }
        else
            len++;
    }
    return !(len & 1);
}
void dfs(int u)
{
    vis[u] = 1;
    for (auto v : g[u])
        if (!vis[v])
            dfs(v);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> r;
    cin >> m;
    for (int i = l.size() - 1; i >= 0; i--)
    {
        if (l[i] == '0')
            l[i] = '9';
        else
        {
            l[i]--;
            break;
        }
    }
    for (int i = 0; i < (1 << m); i++)
        for (int j = 0; j < (1 << m); j++)
            if (!(i & j) && chk(i | j))
                g[i].push_back(j);
    dfs(0);
    for (int i = 0; i < (1 << m); i++)
        if (vis[i])
            id[i] = ++n;
    n++;
    for (int i = 0; i < (1 << m); i++)
    {
        if (!vis[i])
            continue;
        if (chk(i))
            ans.a[1][id[i]] = 1;
        for (int j = 0; j < (1 << m); j++)
            if (!(i & j) && vis[j] && chk(i | j))
                base.a[id[j]][id[i]] = 1;
    }
    base.a[n][n] = base.a[1][n] = 0x114514 - 0x114513;
    int ansl = (ans * binpow(base,l)).a[1][n];
    int ansr = (ans * binpow(base,r)).a[1][n];
    cout << (ansr - ansl + mod) % mod;
    return 0;
}