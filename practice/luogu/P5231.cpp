#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 1.2e7 + 5;
int n,m,cnt;
bool vis[maxm];
char s[maxm],t[maxn][105];
int ch[maxm][4],fail[maxm];
int getid(char ch)
{
    if (ch == 'E')
        return 1;
    else if (ch == 'S')
        return 2;
    else if (ch == 'W')
        return 3;
    return 0;
}
void ins(char s[])
{
    int rt = 0,len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        int dig = getid(s[i]);
        if (!ch[rt][dig])
            ch[rt][dig] = ++cnt;
        rt = ch[rt][dig];
    }
}
void get_fail()
{
    queue<int> q;
    for (int i = 0; i < 4; i++)
        if (ch[0][i])
            q.push(ch[0][i]);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int &v = ch[u][i];
            if (v)
            {
                fail[v] = ch[fail[u]][i];
                q.push(v);
            }
            else
                v = ch[fail[u]][i];
        }
    }
}
void calc(char s[])
{
    int rt = 0,len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        int dig = getid(s[i]);
        rt = ch[rt][dig];
        for (int j = rt; j && !vis[j]; j = fail[j])
            vis[j] = 1;
    }
}
int que(char s[])
{
    int rt = 0,len = strlen(s + 1),res = 0;
    for (int i = 1; i <= len; i++)
    {
        int dig = getid(s[i]);
        rt = ch[rt][dig];
        if (vis[rt])
            res = i;
    }
    return res;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    scanf("%s",s + 1);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s",t[i] + 1);
        ins(t[i]);
    }
    get_fail();
    calc(s);
    for (int i = 1; i <= m; i++)
        printf("%lld\n",que(t[i]));
    return 0;
}
