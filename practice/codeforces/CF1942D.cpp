#include<bits/extc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int n,m;
int a[1005][1005];
queue<int> tmp[1005];
priority_queue<pii> pend;
priority_queue<int> dp[1005];
template<typename typ>
void clear(priority_queue<typ> &q){while (!q.empty())q.pop();}
int get(int x){int res = dp[x].top();dp[x].pop();tmp[x].push(res);return res;}
void solve()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 0; i <= n; i++)
        clear(dp[i]);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            scanf("%lld",a[i] + j);
    dp[0].push(0);
    for (int i = 1; i <= n; i++)
    {
        clear(pend);
        pend.push({a[1][i],-1});
        for (int j = 0; j < i; j++)
            pend.push({get(j) + a[j + 2][i],j});
        for (int j = 1; j <= m && !pend.empty(); j++)
        {
            auto [val,id] = pend.top();
            pend.pop();
            dp[i].push(val);
            if (~id && !dp[id].empty())
                pend.push({get(id) + a[id + 2][i],id});
        }
        for (int j = 0; j < i; j++)
        {
            while (!tmp[j].empty())
            {
                dp[j].push(tmp[j].front());
                tmp[j].pop();
            }
        }
    }
    while (m--)
    {
        printf("%lld%c",dp[n].top(),m ? ' ' : '\n');
        dp[n].pop();
    }
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}