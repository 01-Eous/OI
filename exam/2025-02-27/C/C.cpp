#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e6 + 5;
const int base = 97;
typedef unsigned long long ull;
int n,W,cnt;
int p[maxn],w[maxn];
basic_string<int> ans,tmp;
__gnu_pbds::gp_hash_table<ull,bool>apr; 
ull hsh()
{
    ull ret = 0;
    for (int i = 1; i <= n; i++)
        ret = ret * base + p[i];
    return ret;
}
void dfs()
{
    int hs = hsh();
    if (apr[hs])
        return;
    cnt++,apr[hs] = 1;
    tmp.clear();
    for (int i = 1; i <= n; i++)
        tmp.push_back(p[i]);
    ans = min(tmp,ans); 
    for (int i = 1; i < n; i++)
    {
        if (w[p[i]] + w[p[i + 1]] <= W)
        {
            swap(p[i],p[i + 1]);
            dfs();
            swap(p[i],p[i + 1]);
        }
    }
} 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> W;
    ans.resize(n,inf);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int j = 1; j <= n; j++)
        cin >> w[j];
    dfs();
    cout << cnt << '\n';
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}
