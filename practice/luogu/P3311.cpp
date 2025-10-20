#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,cnt;
bool ed[1505];
char x[1205],s[105];
int dp[1205][1505][2];
struct Klee{int ch[10],fail;}ac[1505];
void ins()
{
    int rt = 0,len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        int dig = s[i] - '0';
        if (!ac[rt].ch[dig])
            ac[rt].ch[dig] = ++cnt;
        rt = ac[rt].ch[dig];
    }
    ed[rt] = 1;
}
void get_fail()
{
    queue<int> q;
    for (int i = 0; i < 10; i++)
        if (ac[0].ch[i])
            q.push(ac[0].ch[i]);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ed[u] |= ed[ac[u].fail];
        for (int i = 0; i < 10; i++)
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
int dfs(int pos,const int rt,bool lim,bool zero)
{
    if (!pos)
        return !zero;
    if (!lim && ~dp[pos][rt][zero])
        return dp[pos][rt][zero];
    int res = 0,up = lim ? x[pos] - '0' : 9;
    for (int i = 0; i <= up; i++)
    {
        int tmp = ac[rt].ch[i];
        if (zero && !i)
            res = (res + dfs(pos - 1,0,lim && i == up,1)) % mod;
        else if (!ed[tmp])
            res = (res + dfs(pos - 1,tmp,lim && i == up,0)) % mod;
    }
    if (!lim)
        dp[pos][rt][zero] = res;
    return res;
}
signed main()
{
    scanf("%s%lld",x + 1,&n);
    for (int i = 1; i <= n; i++)
        scanf("%s",s + 1),ins();
    get_fail();
    memset(dp,0xff,sizeof dp);
    int len = strlen(x + 1);
    reverse(x + 1,x + len + 1);
    printf("%lld",dfs(len,0,1,1));
    return 0;
}