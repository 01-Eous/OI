#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ull = unsigned int;
const int maxn = 1e6 + 5;
const ull base = 7;
int c,n,m;
int a[maxn],b[maxn];
ull ori,hsh,pw[maxn];
int pre[maxn],suf[maxn],lst[maxn];
void init(int n = 1e6 + 1)
{
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * base;
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = 1; i <= m; i++)
        scanf("%lld",b + i);
    memset(lst,0,sizeof(int) * (c + 5));
    ori = 0;
    for (int i = 1; i <= m; i++)
    {
        if (!lst[b[i]])
            pre[i] = 0;
        else
            pre[i] = i - lst[b[i]];
        lst[b[i]] = i;
        ori = ori * base + pre[i];
    }
    memset(lst,0,sizeof(int) * (c + 5));
    hsh = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!lst[a[i]])
            pre[i] = 0;
        else
            pre[i] = i - lst[a[i]];
        lst[a[i]] = i;
        if (i <= m)
            hsh = hsh * base + pre[i];
    }
    memset(lst,0,sizeof(int) * (c + 5));
    for (int i = n; i >= 1; i--)
    {
        if (!lst[a[i]])
            suf[i] = 0;
        else
            suf[i] = lst[a[i]] - i;
        lst[a[i]] = i;
    }
    vector<int> ans;
    for (int i = 1; i + m - 1 <= n; i++)
    {
        if (hsh == ori)
            ans.push_back(i);
        hsh = hsh * base + pre[i + m];// 加入一个
        hsh -= pw[m] * pre[i];// 踢出去一个
        if (suf[i])
        {
            if (suf[i] <= m)
            hsh -= pw[m - suf[i]] * pre[i + suf[i]];// 再踢出去一个
                pre[i + suf[i]] = 0;
        }
    }
    printf("%lu\n",ans.size());
    for (auto i : ans)
        printf("%lld ",i);
    putchar('\n');
}
signed main()
{
    init();
    int t;
    scanf("%lld%lld",&t,&c);
    while (t--)
        solve();
    return 0;
}