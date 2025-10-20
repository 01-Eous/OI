#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int n,cnt;
int dp[maxn];
char s[maxn];
vector<int> g[maxn];
struct Klee{int ch[26],fail,lst,len;}ac[maxn];
void ins()
{
    int len = strlen(s + 1),rt = 0;
    for (int i = 1; i <= len; i++)
    {
        int dig = s[i] - 'a';
        if (!ac[rt].ch[dig])
            ac[rt].ch[dig] = ++cnt;
        rt = ac[rt].ch[dig];
    }
    ac[rt].len = len;
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
        g[ac[u].fail].push_back(u);
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
void dfs(int u,int lst)
{
    ac[u].lst = lst;
    if (ac[u].len)
        lst = u;
    for (auto v : g[u])
        dfs(v,lst);
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%s",s + 1),ins();
    get_fail(),dfs(0,0);
    scanf("%s",s + 1);
    int len = strlen(s + 1),rt = 0;
    dp[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        rt = ac[rt].ch[s[i] - 'a'];
        for (int j = ac[rt].len ? rt : ac[rt].lst; j; j = ac[j].lst)
            if (ac[j].len)
                dp[i] = (dp[i] + dp[i - ac[j].len]) % mod;
    }
    printf("%lld",dp[len]);
    return 0;
}