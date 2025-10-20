#include<bits/extc++.h>
#define int long long
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx","avx2","sse")
using namespace std;
using ull = unsigned int;
const int maxn = 1e6 + 5;
const int mod = 998244353;
int n,m,ans,hsh;
ull pw[maxn];
bool vis[maxn];
vector<int> a;
unordered_map<ull,bool> apr;
void init(int n = 1e6)
{
    pw[0] = 1;
    #pragma GCC unroll 8
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * (m + 5);
}
void dfs()
{
    if (apr.find(hsh) != apr.end())
        return;
    apr[hsh] = 1;
    vector<int> tmp(n + 5);
    for (int i = 1; i <= n - m + 1; i++)
    {
        #pragma GCC unroll 8
        for (int j = i; j - i + 1 <= m; j++)
        {
            tmp[j] = a[j];
            hsh -= pw[j] * a[j];
            a[j] = j - i + 1;
            hsh += pw[j] * a[j];
        }
        dfs();
        #pragma GCC unroll 8
        for (int j = i; j - i + 1 <= m; j++)
        {
            hsh -= pw[j] * a[j];
            a[j] = tmp[j];
            hsh += pw[j] * a[j];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    init();
    a.resize(n + 5);
    #pragma GCC unroll 8
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        hsh += pw[i] * a[i];
    }
    dfs();
    cout << apr.size() << endl;
    cerr << fixed << setprecision(3) << (double)clock() / CLOCKS_PER_SEC;
    return 0;
}