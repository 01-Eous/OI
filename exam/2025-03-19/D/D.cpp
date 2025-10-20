#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m;
char s[10];
unordered_map<int,int> mp;
void ins(int pos,int hs)
{
    if (pos > m)
        return mp[hs]++,void();
    hs *= 30;
    if (s[pos] == '?')
        ins(pos + 1,hs + 27);
    else
    {
        ins(pos + 1,hs + s[pos] - 'a');
        ins(pos + 1,hs + 26);
    }
}
int que(int pos,int hs)
{
    if (pos > m)
        return mp.count(hs) ? mp[hs] : 0;
    hs *= 30;
    int res = 0;
    if (s[pos] == '?')
        res += que(pos + 1,hs + 26);
    else
        res += que(pos + 1,hs + s[pos] - 'a');
    return res + que(pos + 1,hs + 27);
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s",s + 1);
        ans += que(1,0);
        ins(1,0);
    }
    printf("%lld",ans);
    return 0;
}