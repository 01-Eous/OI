#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,nn,k,s,t;
int a[55],c[55][55];
int cnt[maxn],sum[55];
signed main()
{
    scanf("%lld%lld%lld%lld",&nn,&k,&s,&t);
    if ((s & t) != s)
        return printf("0"),0;
    for (int i = 1,x; i <= nn; i++)
    {
        scanf("%lld",&x);
        if ((s & x) == s && (x & t) == x)
            a[++n] = x;
    }
    for (int i = 0; i <= n; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= min(i,k); j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            sum[i] += c[i][j];
        }
    }
    int ans = sum[n],S = t - s;
    for (int x = S; x; x = (x - 1) & S)
    {
        int tmp = 0;
        for (int i = 1; i <= n; i++)
            cnt[a[i] & x]++;
        for (int i = 1; i <= n; i++)
        {
            tmp += sum[cnt[a[i] & x]];
            cnt[a[i] & x] = 0;
        }
        ans += (__builtin_popcountll(x) & 1 ? -1 : 1) * tmp;
    }
    printf("%lld",ans);
    return 0;
}