#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e6 + 5;
int n;
bool ipr[maxn];
int a[maxn],phi[maxn];
vector<int> pr;
int binpow(int x,int y,int mod)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
        {
            res = res * x;
            if (res > mod)
                res = res % mod + mod;
        }
        x *= x;
        if (x > mod)
            x = x % mod + mod;
        y >>= 1;
    }
    return res;
}
void prime(int n = 2e6)
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
        {
            pr.push_back(i);
            phi[i] = i - 1;
        }
        for (auto j : pr)
        {
            if (i * j > n)
                break;
            ipr[i * j] = 1;
            if (i % j == 0)
            {
                phi[i * j] = phi[i] * j;
                break;
            }
            else
                phi[i * j] = phi[i] * (j - 1);
        }
    }
}
int solve(int pos,int mod)
{
    if (pos == n + 1 || mod == 1)
        return 1;
    return binpow(a[pos],solve(pos + 1,phi[mod]),mod);
}
signed main()
{
    prime();
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    printf("%lld",solve(1,10007) % 10007);
    return 0;
}