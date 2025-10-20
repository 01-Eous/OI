#include<bits/extc++.h>
using namespace std;
using ld = double;
const int maxn = 1e5 + 5;
int n;
ld a[maxn],b[maxn];
bool visa[maxn],visb[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    sort(a + 1,a + n + 1,greater<>());
    sort(b + 1,b + n + 1,greater<>());
    int p1 = 1,p2 = 1;
    ld suma = 0,sumb = 0,ans = 0;
    while (p1 <= n && p2 <= n)
    {
        suma += a[p1] * (!visa[p1]);
        sumb += b[p2] * (!visb[p2]);
        visa[p1] = visb[p2] = 1;
        ans = max(ans,min(suma - p1 - p2,sumb - p1 - p2));
        if (suma <= sumb)
            p1++;
        if (sumb <= suma)
            p2++;
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}