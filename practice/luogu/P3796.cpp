#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n,cnt;
char s[155][75],t[maxn];
int pos[155],in[maxn];
struct Klee{int ch[26],fail,sum;}ac[maxn];
void ins(int id,char *s)
{
    int rt = 0,len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        int dig = s[i] - 'a';
        if (!ac[rt].ch[dig])
        {
            ac[rt].ch[dig] = ++cnt;
            memset(&ac[cnt],0,sizeof ac[cnt]);
        }
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
        in[ac[u].fail]++;
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
void que(char s[])
{
    int rt = 0,len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        rt = ac[rt].ch[s[i] - 'a'];
        ac[rt].sum++;
    }
}
void topsort()
{
    queue<int> q;
    for (int i = 0; i <= cnt; i++)
        if (!in[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        cerr << u << endl;
        q.pop();
        int v = ac[u].fail;
        ac[v].sum += ac[u].sum;
        if (!--in[v])
            q.push(v);
    }
}
void solve()
{
    cnt = 0;
    memset(in,0,sizeof in);
    memset(&ac[0],0,sizeof ac[0]);
    for (int i = 1; i <= n; i++)
        scanf("%s",s[i] + 1),ins(i,s[i]);
    get_fail();
    scanf("%s",t + 1),que(t);
    topsort();
    int _max = 0;
    for (int i = 1; i <= n; i++)
        _max = max(_max,ac[pos[i]].sum);
    printf("%d\n",_max);
    for (int i = 1; i <= n; i++)
        if (ac[pos[i]].sum == _max)
            puts(s[i] + 1);
}
signed main()
{
    scanf("%d",&n);
    while (n)
    {
        solve();
        scanf("%d",&n);
    }
    return 0;
}