#include<bits/extc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 3005;
int n,k;
char s[maxn];
int a[maxn],sum[maxn][maxn];
class bits
{
    private:
    ull d[(maxn >> 6) + 5];
    public:
    bits(){memset(d,0,sizeof d);};
    void clear(){memset(d,0,sizeof(ull) * (k + 5));}
    void print()
    {
        for (int i = 0; i <= k; i++)
            for (int j = 63; j >= 0; j--)
                printf("%lld",(d[i] >> j) & 1);
    }
    bits& set(int x)
    {
        d[x >> 6] |= 1ULL << (x & 0x3f);
        return *this;
    }
    bool que(int x)
    {
        assert(x >> 6 <= k);
        return d[x >> 6] & (1ULL << (x & 0x3f));
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
}pos[26],f[maxn],dp[maxn],tmp;
int calc(const vector<int> &v1,const vector<int> &v2)
{
    tmp.clear();
    for (int i = 1; i <= n; i++)
        f[i].clear();
    for (int i = 0; i < 26; i++)
        pos[i].clear();
    for (int i = 1; i < v1.size(); i++)
        pos[v1[i]].set(i);
    for (int i = 1; i < v2.size(); i++)
    {
        tmp = (f[i] = f[i - 1]) | pos[v2[i]];
        f[i].shift(),f[i].set(0);
        f[i] = ((tmp - f[i]) ^ tmp) & tmp;
    }
    return f[v2.size() - 1].count();
}
void solve()
{
    scanf("%s",s + 1);
    k = (n = strlen(s + 1)) >> 6;
    for (int i = 1; i <= n; i++)
        a[i] = s[i] - 'a';
    int ans = 0,tmp;
    vector<int> v1,v2,tmp1,tmp2;
    for (int i = 2; i <= n; i++)
    {
        tmp1 = tmp2 = {0};
        for (int j = 1; j < i; j++)
            tmp1.push_back(a[j]);
        for (int j = i; j <= n; j++)
            tmp2.push_back(a[j]);
        tmp = calc(tmp1,tmp2);
        if (tmp > ans)
        {
            ans = tmp;
            v1 = tmp2,v2 = tmp1;
            memcpy(dp,f,sizeof(bits) * (n + 5));
        }
    }
    printf("%d\n",ans << 1);
    if (!ans)
        return;
    for (int i = 1; i < v1.size(); i++)
        for (int j = 1; j < v2.size(); j++)
            sum[i][j] = sum[i][j - 1] + dp[i].que(j);
    memset(s,0,sizeof(char) * (n + 5));
    int x = v1.size() - 1,y = v2.size() - 1;
    while (sum[x][y] > 0)
    {
        if (v1[x] == v2[y])
        {
            s[sum[x][y]] = v1[x] + 'a';
            x--,y--;
        }
        else
        {
            if (sum[x][y] == sum[x - 1][y])
                x--;
            else
                y--;
        }
    }
    printf("%s%s\n",s + 1,s + 1);
}
signed main()
{
    int t;
    scanf("%d",&t);
    for (int i = 1; i <= t; i++)
    {
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}