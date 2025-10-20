#include<bits/extc++.h>
#define int long long
using namespace std;
int n,s,t,mod;
int a[15],b[15],c[15];
int ccb(int x)// C(x + n,n)
{
    if (x < 0)
        return 0;
    vector<int> vec;
    for (int i = x + 1; i <= x + n; i++)
        vec.push_back(i);
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        for (auto &j : vec)
            if (int g = __gcd(tmp,j); g > 1)
                tmp /= g,j /= g;
    }
    int res = 1;
    for (auto i : vec)
        res = res * i % mod;
    return res;
}
int calc(int x)
{
    if (x < 0)
        return 0;
    int res = 0;
    for (int s = 0; s < (1 << n); s++)
    {
        int tmp = x,cnt = 0;
        for (int i = 1; i <= n; i++)
            if ((s >> (i - 1)) & 1)
                tmp -= c[i] + 1,cnt++;
        res = (res + (cnt & 1 ? -1 : 1) * ccb(tmp) + mod) % mod;
    }
    return res;
}
signed main()
{
    freopen("preprocessor.in","r",stdin);
    freopen("preprocessor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s >> t >> mod;
    int sum = 0;
    for (int i = 1,p; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> p;
        a[i] += (a[i] & 1) ^ p;
        sum += a[i];
        c[i] = (b[i] - a[i]) >> 1;
    }
    s = floor((s - 1 - sum) / 2.0);
    t = floor((t - sum) / 2.0);
    cout << (calc(t) - calc(s) + mod) % mod;
    return 0;
}