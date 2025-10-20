#include<bits/extc++.h>
#define int long long
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx","avx2","sse")
using namespace std;
const int maxn = 4e5 + 5;
int n;
int a[maxn];
bool ipr[(int)1e7 + 5];
vector<int> pr;
map<int,int> apr;
void prime(int n = 1e7)
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
            pr.push_back(i);
        for (int j : pr)
        {
            if (i * j > n)
                break;
            ipr[i * j] = 1;
            if (i % j == 0)
                break;
        }
    }
}
void solve()
{
    scanf("%lld",&n);
    #pragma GCC unroll 8
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    apr.clear();
    sort(a + 1,a + n + 1,greater<>());
    int j = 0,cnt = 0,sum = 0;
    #pragma GCC unroll 8
    for (int i = 1; i <= n; i++)
    {
        if (sum >= pr[j] - a[i])
        {
            sum -= pr[j] - a[i];
            apr[pr[j]] = 1;
        }
        else
            cnt++;
        while (j < pr.size() && apr[pr[j]])
            j++;
    }
    printf("%lld\n",cnt);
}
signed main()
{
    prime();
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}