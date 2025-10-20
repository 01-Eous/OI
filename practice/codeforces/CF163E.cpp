#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n,k,cnt,tim;
char s[maxn];
bool vis[maxn];
int dfn[maxn],ed[maxn];
int tree[maxn],pos[maxn];
vector<int> g[maxn];
struct Klee{int ch[26],fail;}ac[maxn];
void ins(int id)
{
    int rt = 0,len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        int dig = s[i] - 'a';
        if (!ac[rt].ch[dig])
            ac[rt].ch[dig] = ++cnt;
        rt = ac[rt].ch[dig];
    }
    pos[id] = rt;
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
int lowbit(const int &x){return x & -x;}
void dfs(int u)
{
    dfn[u] = ++tim;
    for (auto v : g[u]) 
        dfs(v);
    ed[u] = tim;
}
void add(int i,int x)
{
    for (; i; i -= lowbit(i))
        tree[i] += x;
}
void upd(int l,int r,int x)
{
    add(r,x);
    add(l - 1,-x);
}
int que(int i)
{
    int res = 0;
    for (; i <= tim; i += lowbit(i))
        res += tree[i];
    return res;
}
int que()
{
    int rt = 0,len = strlen(s + 1),res = 0;
    for (int i = 1; i <= len; i++)
    {
        rt = ac[rt].ch[s[i] - 'a'];
        res += que(dfn[rt]);
    }
    return res;
}
signed main()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= k; i++)
        scanf("%s",s + 1),ins(i);
    get_fail(),dfs(0);
    for (int i = 1; i <= k; i++)
        vis[i] = 1,upd(dfn[pos[i]],ed[pos[i]],1);
    while (n--)
    {
        scanf("%s",s);
        if (s[0] == '+')
        {
            int x = atoi(s + 1);
            if (!vis[x])
                vis[x] = 1,upd(dfn[pos[x]],ed[pos[x]],1);
        }
        else if (s[0] == '-')
        {
            int x = atoi(s + 1);
            if (vis[x])
                vis[x] = 0,upd(dfn[pos[x]],ed[pos[x]],-1);
        }
        else
            printf("%d\n",que());
    }
    return 0;
}