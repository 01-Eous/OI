#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,q,cnt;
char s[105];
int mp[105][105];
int dp[105][105][205];
struct Klee{int ch[2],fail,sum;}ac[205];
int toint(char ch)
{
    if (ch == 'r')
        return 0;
    else
        return 1;
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
    ac[rt].sum += len;
}
void get_fail()
{
    queue<int> q;
    for (int i = 0; i < 2; i++)
        if (ac[0].ch[i])
            q.push(ac[0].ch[i]);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ac[u].sum += ac[ac[u].fail].sum;
        for (int i = 0; i < 2; i++)
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
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s",s + 1);
        for (int j = 1; j <= m; j++)
            mp[i][j] = s[j] - '0';
    }
    scanf("%lld",&q);
    while (q--)
        scanf("%s",s + 1),ins();
    get_fail();

    memset(dp,~0x3f,sizeof(dp));
    dp[1][1][0] = mp[1][1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int rt = 0,x,y,v; rt <= cnt; rt++)
            {
                x = i,y = j + 1,v = ac[rt].ch[0];
                if (mp[x][y])
                    dp[x][y][v] = max(dp[x][y][v],dp[i][j][rt] + mp[x][y] + ac[v].sum);
                    
                x = i + 1,y = j,v = ac[rt].ch[1];
                if (mp[x][y])
                    dp[x][y][v] = max(dp[x][y][v],dp[i][j][rt] + mp[x][y] + ac[v].sum);
            }
        }
    }
    int ans = 0;
    for (int rt = 0; rt <= cnt; rt++)
        ans = max(ans,dp[n][m][rt]);
    printf("%lld",ans ? ans : -1LL);
    return 0;
}