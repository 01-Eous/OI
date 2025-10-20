#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
using ll = long long;
int n,len;
char t[maxn],s[maxn];
ll f1[maxn],f2[maxn];
class acam
{
    private:
    int cnt;
    struct Nahida{int ch[26],fail,sum;}ac[maxn];
    public:
    void ins(int len)
    {
        int rt = 0;
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
            ac[u].sum += ac[ac[u].fail].sum;
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
    void que(int len,ll f[])
    {
        int rt = 0;
        for (int i = 1; i <= len; i++)
        {
            rt = ac[rt].ch[t[i] - 'a'];
            f[i] = ac[rt].sum;
        }
    }
}a,b;
signed main()
{
    scanf("%s%d",t + 1,&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s",s + 1);
        len = strlen(s + 1);
        a.ins(len);
        reverse(s + 1,s + len + 1);
        b.ins(len);
    }
    a.get_fail(),b.get_fail();
    len = strlen(t + 1);
    a.que(len,f1);
    reverse(t + 1,t + len + 1);
    b.que(len,f2);
    ll ans = 0;
    for (int i = 1; i <= len; i++)
        ans += f1[len - i] * f2[i];
    printf("%lld",ans);
    return 0;
}