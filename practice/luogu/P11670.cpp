#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n,ans;
int a[maxn],b[maxn];
int cnt1[maxn],cnt2[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (a[i] == b[i])
            ans += min(i,n - i + 1) + (i * (i - 1) + (n - i + 1) * (n - i)) / 2;
    }
    int l = (n >> 1),r = (n >> 1) + 1;
    while (1)
    {
        if (r > n)
            break;
        ans += (cnt1[b[r]] + cnt2[a[r]]) * (n - r + 1);
        cnt1[a[r]]++,cnt2[b[r]]++;
        if (l < 1)
            break;
        ans += (cnt1[b[l]] + cnt2[a[l]]) * l;
        cnt1[a[l]]++,cnt2[b[l]]++;
        l--,r++;
    }
    cout << ans;
    return 0;
}