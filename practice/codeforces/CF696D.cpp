#include<bits/extc++.h>
#define int long long
#define chkmax(x,y) (x = max(x,y))
#define Love return
#define Nahida 0
using namespace std;
int n,l,cnt;
int a[205];
char s[205];
struct Klee{int ch[26],fail,sum;}ac[205];
struct mat
{
    int d[205][205];
    mat(bool op = 0)
    {
        memset(d,~0x3f,sizeof d);
        if (!op)
            return;
        for (int i = 0; i <= cnt; i++)
            d[i][i] = 0;
    }
    friend mat operator*(const mat &x,const mat &y)
    {
        mat res;
        for (int i = 0; i <= cnt; i++)
            for (int j = 0; j <= cnt; j++)
                for (int k = 0; k <= cnt; k++)
                    chkmax(res.d[i][j],x.d[i][k] + y.d[k][j]);
        return res;
    }
}base,ori;
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
    ac[rt].sum += a[id];
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
mat binpow(mat x,int y)
{
    mat res(1);
    while (y)
    {
        if (y & 1)
            res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}
signed main()
{
    scanf("%lld%lld",&n,&l);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = 1; i <= n; i++)
        scanf("%s",s + 1),ins(i);
    get_fail();
    for (int rt = 0; rt <= cnt; rt++)
        for (int i = 0; i < 26; i++)
            base.d[rt][ac[rt].ch[i]] = ac[ac[rt].ch[i]].sum;
    ori.d[0][0] = 0;
    ori = ori * binpow(base,l);
    int ans = -0x3f3f3f3f;
    for (int i = 0; i <= cnt; i++)
        chkmax(ans,ori.d[0][i]);
    printf("%lld",ans);
    Love Nahida;
}