#include<bits/extc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 7e4 + 5;
int n,m,k;
class bits
{
    private:
    ull d[(maxn >> 6) + 5];
    public:
    bits(){memset(d,0,sizeof d);};
    bits& set(int x)
    {
        d[x >> 6] |= 1ULL << (x & 0x3f);
        return *this;
    }
    int count()
    {
        int res = 0;
        for (int i = 0; i <= k; i++)
            res += __builtin_popcountll(d[i]);
        return res;
    }
    bits &shift()
    {
        ull lst = 0;
        for (int i = 0; i <= k; i++)
        {
            int tmp = d[i] >> 0x3f;
            d[i] = (d[i] << 1) | lst;
            lst = tmp;
        }
        return *this;
    }
    friend bits operator&(const bits &x,const bits &y)
    {
        bits res;
        for (int i = 0; i <= k; i++)
            res.d[i] = x.d[i] & y.d[i];
        return res;
    }
    friend bits operator|(const bits &x,const bits &y)
    {
        bits res;
        for (int i = 0; i <= k; i++)
            res.d[i] = x.d[i] | y.d[i];
        return res;
    }
    friend bits operator^(const bits &x,const bits &y)
    {
        bits res;
        for (int i = 0; i <= k; i++)
            res.d[i] = x.d[i] ^ y.d[i];
        return res;
    }
    friend bits operator-(const bits &x,const bits &y)
    {
        bits res;
        ull lst = 0;
        for (int i = 0; i <= k; i++)
        {
            res.d[i] = (x.d[i] - y.d[i] - lst);
            lst = x.d[i] < y.d[i] + lst;
        }
        return res;
    }
}pos[maxn],dp,tmp;
signed main()
{
    scanf("%d%d",&n,&m);
    k = n >> 6;
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%d",&x);
        pos[x].set(i);
    }
    for (int i = 1,x; i <= m; i++)
    {
        scanf("%d",&x);
        tmp = dp | pos[x];
        dp.shift(),dp.set(0);
        dp = ((tmp - dp) ^ tmp) & tmp;
    }
    printf("%d\n",dp.count());
    return 0;
}