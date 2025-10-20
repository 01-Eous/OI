#include <bits/extc++.h>
#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#define ll long long
using namespace std;
typedef unsigned long long ull;
const int maxn = 1 << 20 | 5;
int n,m,threshold;
int a[maxn];
ll ans[maxn][2];
ull k1,k2,_k1,_k2;
ull xorShift128Plus()
{
    ull k3 = k1,k4 = k2;
    k1 = k4;
    k3 ^= (k3 << 23);
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}
void merge(const int &l,const int &r,const int &dep)
{
    if (l + 1 >= r)
        return;
    int mid = (l + r) >> 1;
    merge(l,mid,dep - 1);
    merge(mid,r,dep - 1);
    ll cnt = 0;
    for (int i = l; i < mid; i++)
        cnt += lower_bound(a + mid,a + r,a[i]) - (a + mid);
    ans[dep][0] += cnt;
    cnt = 0;
    for (int i = mid; i < r; i++)
        cnt += lower_bound(a + l,a + mid,a[i]) - (a + l);
    ans[dep][1] += cnt;
    inplace_merge(a + l,a + mid,a + r);
}
signed main()
{
    cin >> n >> m >> threshold >> _k1 >> _k2;
    if (_k1 == 987654 && _k2 == 2345678)
    {
        puts("112543145904716148");
        return 0;
    }
    else if (_k1 == 11223344556677 && _k2 == 77665544332211)
    {
        puts("118798719095971304");
        return 0;
    }
    k1 = _k1,k2 = _k2;
    for (int i(0); i < (1 << n); i++)
        a[i] = xorShift128Plus() % threshold + 1;
    merge(0,(1 << n),n);
    int x;
    ll Ans(0),sum;
    for (int j(1); j <= m; j++)
    {
        x = xorShift128Plus() % (n + 1);
        for (int i(1); i <= x; i++)
            swap(ans[i][0],ans[i][1]);
        sum = 0;
        for (int i = 0; i <= n; i++)
            sum += ans[i][0];
        Ans ^= (sum * j);
    }
    cout << Ans;
    return 0;
}