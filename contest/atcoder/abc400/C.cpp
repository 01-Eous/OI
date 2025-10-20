#include<bits/extc++.h>
#define int long long
using namespace std;
int n,ans;
signed main()
{
    cin >> n;
    int ans = 0;
    for (int i = 1; 1 << (2 * i) <= n; i++)
        ans += (int)floor(sqrt(n / (1 << (2 * i)))) >> 1;
    for (int i = 1; 1 << (2 * i + 1) <= n; i++)
        ans += (int)floor(sqrt(n / (1 << (2 * i + 1)))) >> 1;
    cout << ans;
    return 0;
}
