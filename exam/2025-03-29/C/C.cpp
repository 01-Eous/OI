#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e4 + 5;
int n;
int a[maxn],b[maxn],p[maxn],c[maxn];
bool cmp(int i,int j){return min(a[i],b[j]) < min(a[j],b[i]);}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        p[i] = i;
    }
    sort(p + 1,p + n + 1,cmp);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[p[i]];
        c[i] = max(sum,c[i - 1]) + b[p[i]];
    }
    cout << c[n] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}