#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n,mod,k;
int a[maxn],b[maxn],val[maxn];
bool apr[1005];
random_device seed;
inline void read(int &x)
{
    x = 0; int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
inline bool check(int mid)
{
    int sum = 0,cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] > mid)
            return 0;
        sum += b[i];
        if (sum > mid)
        {
            cnt++;
            sum = b[i];
        }
    }
    return cnt <= k;
}
inline void cpy(int x)
{
    for (int i = 1; i <= n; i++)
        b[i] = (a[i] + x) % mod;
}
inline int bin()
{
    int l = 0,r = n * mod,mid,ret = inf;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
        {
            ret = min(ret,mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ret;
}
signed main()
{
    srand(seed());
    read(n),read(mod),read(k);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    iota(val,val + mod,0);
    random_shuffle(val,val + mod);
    cpy(val[0]);
    int ans = bin();
    for (int i = 1; i < mod; i++)
    {
        cpy(val[i]);
        if (!check(ans - 1))
            continue;
        ans = min(ans,bin());
    }
    printf("%d",ans);
    return 0;
}