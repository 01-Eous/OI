#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,m;
int a[maxn];
vector<int> vec;
int phi(int x)
{
    int res = x,up = x;
    for (int i = 2; i * i <= up; i++)
    {
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x != 1)
        res = res / x * (x - 1);
    return res;
}
int binpow(int x,int y,int mod)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    n <<= 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m != 1)
    {
        vec.push_back(m);
        m = phi(m);
    }
    vec.push_back(1);
    for (int i = 1; i <= n; i++)
    {
        int ans = 1;
        for (int j = vec.size() - 1; ~j; j--)
            if (i - j >= 1)
                ans = binpow(a[i - j] % vec[j],ans,vec[j]);
        cout << ans << ' ';
    }
    return 0;
}