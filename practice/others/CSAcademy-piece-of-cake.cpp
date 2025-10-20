#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int maxv = 3 << 24;
int n;
int a[maxn],ans[2];
vector<int> num[30];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int tmp = 0;
        while (1 << tmp <= a[i])
            tmp++;
        num[tmp].push_back(a[i] * maxv);
    }
    bool op = 0;
    for (int i = 20; i > 0; i--)
    {
        sort(num[i].begin(),num[i].end(),greater<>());
        for (auto x : num[i])
        {
            ans[op] += x >> 1;
            num[i - 1].push_back(x >> 1);
            op ^= 1;
        }
    }
    if (n & 1)
    {
        for (auto i : num[0])
        {
            ans[op] += (i << 1) / 3;
            op ^= 1;
            ans[op] += i / 3;
        }
    }
    else
    {
        for (auto i : num[0])
        {
            ans[op] += i;
            op ^= 1;
        }
    }
    int d = __gcd(ans[0],maxv);
    cout << ans[0] / d << '/' << maxv / d << '\n';
    d = __gcd(ans[1],maxv);
    cout << ans[1] / d << '/' << maxv / d << '\n';
    return 0;
}