#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n,k,cnt;
int ch[maxn * 30][2],pos[maxn * 30];
void ins(int x,int id)
{
    int rt = 1;
    for (int i = 30; i >= 0; i--)
    {
        bool dig = (x >> i) & 1;
        if (!ch[rt][dig])
            ch[rt][dig] = ++cnt;
        rt = ch[rt][dig];
        pos[rt] = max(pos[rt],id);
    }
}
int que(int x)
{
    int sum = 0,res = 0,rt = 1;
    for (int i = 30; i >= 0; i--)
    {
        bool dig = (x >> i) & 1;
        if (ch[rt][dig ^ 1])
        {
            if ((sum ^ (1 << i)) >= k)
            {
                res = max(res,pos[ch[rt][dig ^ 1]]);
                rt = ch[rt][dig];
            }
            else
            {
                sum ^= (1 << i);
                rt = ch[rt][dig ^ 1];
            }
        }
        else if (ch[rt][dig])
            rt = ch[rt][dig];
        else
            break;
    }
    return res;
}
void solve()
{
    for (int i = 1; i <= cnt; i++)
        ch[i][0] = ch[i][1] = pos[i] = 0;
    cnt = 1;
    scanf("%d%d",&n,&k);
    int ans = inf;
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%d",&x);
        ins(x,i);
        if (int tmp = que(x); tmp)
            ans = min(ans,i - tmp + 1);
    }
    if (k == 0)
        return (void)puts("1");
    if (ans == inf)
        puts("-1");
    else
        printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}