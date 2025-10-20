#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,sum;
int a[maxn];
bool calc(int s,int t)
{
    while (a[s] == a[t] && s < t)
        s++,t--;
    if (s > t)
        return 1;
    for (int i = s; i <= t; i += 2)
        if (a[i] != a[i + 1])
            return 0;
    return 1;
}
void solve()
{
    scanf("%lld",&n);
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        sum ^= a[i];
    }
    if (sum == 0)
        return (void)puts("Draw");
    int pos = 30;
    while (pos >= 0)
    {
        if (sum & (1 << pos))
            break;
        pos--;
    }
    for (int i = 1; i <= n; i++)
        a[i] = (a[i] >> pos) & 1;
    sum = 0;
    for (int i = 1; i <= n; i++)
        sum += a[i];
    if ((n & 1) == 0)
        return (void)puts("Alice");
    if (!a[1] && !a[n])
        puts("Bob");
    else if (sum % 4 == 1)
    {
        if (a[1] && a[n])
        {
            if (calc(1,n - 1) || calc(2,n))
                puts("Alice");
            else
                puts("Bob");
        }
        else if (a[1])
        {
            if (calc(2,n))
                puts("Alice");
            else
                puts("Bob");
        }
        else
        {
            if (calc(1,n - 1))
                puts("Alice");
            else
                puts("Bob");
        }
    }
    else
        puts("Bob");
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}