#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n,cnt,ans;
char s[maxn];
struct Klee{int ch[26],fail,sum;}ac[maxn];
void ins()
{
    int rt = 0,len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        int dig = s[i] - 'a';
        if (!ac[rt].ch[dig])
            ac[rt].ch[dig] = ++cnt;
        rt = ac[rt].ch[dig];
    }
    ac[rt].sum++;
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
void que()
{
    int rt = 0,len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        rt = ac[rt].ch[s[i] - 'a'];
        for (int j = rt; j && ~ac[j].sum; j = ac[j].fail)
        {
            ans += ac[j].sum;
            ac[j].sum = -1;
        }
    }
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%s",s + 1),ins();
    get_fail();
    scanf("%s",s + 1),que();
    printf("%d",ans);
    return 0;
}