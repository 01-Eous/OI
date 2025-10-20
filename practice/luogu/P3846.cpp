#include<bits/extc++.h>
#define int long long
using namespace std;
int a,b,mod;
unordered_map<int,int> mp;
int binpow(int x,int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
int bsgs(int a,int b)
{
    a %= mod,b %= mod;
    if (a == b)
        return 1;
    else if (!a && b)
        return -1;
    int len = sqrt(mod) + 1,tmp = binpow(a,len);
    for (int i = 0; i <= len; i++)
        mp[b] = i,b = b * a % mod;
    b = 1;
    for (int i = 1; i <= len; i++)
        if (mp.find(b = b * tmp % mod) != mp.end())
            return i * len - mp[b];
    return -1;
}
signed main()
{
    scanf("%lld%lld%lld",&mod,&a,&b);
    int ans = bsgs(a,b);
    if (~ans)
        printf("%lld",ans);
    else
        printf("no solution");
    return 0;
}