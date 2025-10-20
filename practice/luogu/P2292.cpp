#include<bits/extc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int n,m,cnt,max1;
char s[maxn];
bool dp[maxn];
int q[maxn],head,tail;
int ch[maxn][26],len[maxn],fail[maxn];
void ins(int n)
{
    int rt = 0;
    for (int i = 1; i <= n; i++)
    {
        int dig = s[i] - 'a';
        if (!ch[rt][dig])
            ch[rt][dig] = ++cnt;
        rt = ch[rt][dig];
    }
    len[rt] = n;
    max1 = max(max1,n);
}
void get_fail()
{
    head = 1,tail = 0;
    for (int i = 0; i < 26; i++)
        if (ch[0][i])
            q[++tail] = ch[0][i];
    while (head <= tail)
    {
        int u = q[head++];
        for (int i = 0; i < 26; i++)
        {
            int &v = ch[u][i];
            if (v)
            {
                fail[v] = ch[fail[u]][i];
                q[++tail] = v;
            }
            else
                v = ch[fail[u]][i];
        }
    }
}
void solve(int n)
{
    fill(dp + 1,dp + n + 1,0);
    dp[0] = 1;
    int rt = 0,ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ans + max1 < i)
            break;
        int dig = s[i] - 'a';
        rt = ch[rt][dig];
        for (int j = rt; j && !dp[i]; j = fail[j])
            dp[i] |= dp[i - len[j]];
        if (dp[i])
            ans = i;
    }
    printf("%d\n",ans);
}
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s",s + 1);
        ins(strlen(s + 1));
    }
    get_fail();
    for (int i = 1; i <= m; i++)
    {
        scanf("%s",s + 1);
        solve(strlen(s + 1));
    }
    return 0;
}