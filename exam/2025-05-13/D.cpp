#include<bits/extc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int mod[] = {0,0,1,3,0,4};
int t,n,m;
bitset<maxn> mp[maxn],sta,tmp;
mt19937 rnd(random_device{}());
struct edge{int u,v;}e[(int)5e5 + 5];
void solve()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        mp[i].reset();
    for (int i = 1; i <= m; i++)
    {
        auto &[u,v] = e[i];
        scanf("%d%d",&u,&v);
        mp[u][v] = mp[v][u] = 1;
    }
    int st = clock();
    while ((clock() - st) / (double)CLOCKS_PER_SEC < 1.95 / t)
    {
        sta.reset();
        for (int i = 1; i <= n; i++)
            sta[i] = rnd() & 1;
        int sum = 0;
        for (int i = 1; i <= m; i++)
        {
            auto [u,v] = e[i];
            if (!sta[u] || !sta[v])
                continue;
            tmp = mp[u] & mp[v] & sta;
            int cnt = tmp.count();
            sum = (sum + mod[cnt % 6]) % 6;
        }
        if (sum == 1)
            return (void)puts("YES");
    }
    puts("NO");
}
signed main()
{
    scanf("%d",&t);
    for (int i = 1; i <= t; i++)
        solve();
    fprintf(stderr,"%.3lf",clock() / (double)CLOCKS_PER_SEC);
    return 0;
}