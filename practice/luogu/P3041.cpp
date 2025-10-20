#include<bits/extc++.h>
using namespace std;
int n,m,cnt;
char s[20];
int dp[1005][3005];
struct Klee{int ch[3],fail,sum;}ac[3005];
void ins()
{
    int rt = 0,len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        int dig = s[i] - 'A';
        if (!ac[rt].ch[dig])
            ac[rt].ch[dig] = ++cnt;
        rt = ac[rt].ch[dig];
    }
    ac[rt].sum++;
}
void get_fail()
{
    queue<int> q;
    for (int i = 0; i < 3; i++)
        if (ac[0].ch[i])
            q.push(ac[0].ch[i]);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ac[u].sum += ac[ac[u].fail].sum;
        for (int i = 0; i < 3; i++)
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
    while (n--)
        scanf("%s",s + 1),ins();
    get_fail();
    memset(dp,~0x3f,sizeof dp);
    dp[0][0] = 0;
    for (int i = 0; i < m; i++)
    {
        for (int rt = 0; rt <= cnt; rt++)
        {
            for (int j = 0; j < 3; j++)
            {
                int v = ac[rt].ch[j];
                dp[i + 1][v] = max(dp[i + 1][v],dp[i][rt] + ac[v].sum);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= cnt; i++)
        ans = max(ans,dp[m][i]);
    printf("%d",ans);
    return 0;
}