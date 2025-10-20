#include<bits/extc++.h>
using namespace std;
const int mod = 1e4 + 7;
int n,m,cnt;
char s[105];
int dp[105][6005];
struct Klee
{
    bool fl;
    int ch[26],fail;
}ac[6005];
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
    ac[rt].fl = 1;
}
void get_fail()
{
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (ac[0].ch[i])
            q.push(ac[0].ch[i]);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ac[u].fl |= ac[ac[u].fail].fl;
        for (int i = 0; i < 26; i++)
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
    int ans = 1;
    for (int i = 1; i <= m; i++)
        ans = ans * 26 % mod;
    while (n--)
        scanf("%s",s + 1),ins();
    get_fail();
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
        for (int rt = 0; rt <= cnt; rt++)
            for (int j = 0; j < 26; j++)
                if (int v = ac[rt].ch[j]; !ac[v].fl)
                    dp[i + 1][v] = (dp[i + 1][v] + dp[i][rt]) % mod;
    for (int i = 0; i <= cnt; i++)
        ans = (ans - dp[m][i] + mod) % mod;
    printf("%d",ans);
    return 0;
}