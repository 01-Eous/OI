#include<bits/extc++.h>
#define add(x,y) (x = (x + y) % mod)
using namespace std;
using ll = long long;
const ll mod = 1e9 + 9;
int n,m,cnt,maxl;
char s[15];
int val[105];
ll dp[1005][15][105];
struct Klee{int ch[4],fail;}ac[105];
int toint(const char &x)
{
    if (x == 'A')
        return 0;
    else if (x == 'G')
        return 1;
    else if (x == 'C')
        return 2;
    return 3;
}
void ins()
{
    int rt = 0,len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        int dig = toint(s[i]);
        if (!ac[rt].ch[dig])
            ac[rt].ch[dig] = ++cnt;
        rt = ac[rt].ch[dig];
    }
    val[rt] = len;
}
void get_fail()
{
    queue<int> q;
    for (int i = 0; i < 4; i++)
        if (ac[0].ch[i])
            q.push(ac[0].ch[i]);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        val[u] = max(val[u],val[ac[u].fail]);
        for (int i = 0; i < 4; i++)
        {
            int &v = ac[u].ch[i];
            if (v)
            {
                ac[v].fail = ac[ac[u].fail].ch[i];
                q.push(v);
            }
            else
                v = ac[ac[u].fail].ch[i];
        }
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    while (m--)
    {
        scanf("%s",s + 1);
        ins(),maxl = max(maxl,(int)strlen(s + 1));
    }
    get_fail();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= maxl; j++)
        {
            for (int k = 0; k <= cnt; k++)
            {
                if (!dp[i][j][k])
                    continue;
                for (int dig = 0; dig < 4; dig++)
                {
                    int rt = ac[k].ch[dig];
                    if (val[rt] > j)
                        add(dp[i + 1][0][rt],dp[i][j][k]);
                    else
                        add(dp[i + 1][j + 1][rt],dp[i][j][k]);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= cnt; i++)
        add(ans,dp[n][0][i]);
    printf("%lld",ans);
    return 0;
}