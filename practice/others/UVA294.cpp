#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int l,r,idx;
int pr[maxn];
bool ipr[maxn];
void init(int n = 1e5)
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
            pr[++idx] = i;
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            ipr[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
        }
    }
}
int calc(int x)
{
    int up = x,res = 1;
    for (int i = 1; i <= idx && pr[i] * pr[i] <= up; i++)
    {
        int cnt = 1;
        while (x % pr[i] == 0)
        {
            cnt++;
            x /= pr[i];
        }
        res *= cnt;
    }
    if (x > 1)
        res <<= 1;
    return res;
}
void solve()
{
    scanf("%lld%lld",&l,&r);
    int ans = 0,max1 = 0;
    for (int i = l; i <= r; i++)
    {
        int tmp = calc(i);
        if (tmp > max1)
        {
            max1 = tmp;
            ans = i;
        }
    }
    printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,r,ans,max1);
}
signed main()
{
    init();
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}
