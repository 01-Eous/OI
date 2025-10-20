#include<bits/extc++.h>
using namespace std;
const int maxn = 2e4 + 5;
int n;
int p[maxn],a[maxn],b[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = maxn * i;
        b[i] = maxn * (n - i) + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        a[p[i]] += i;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
    for (int j = 1; j <= n; j++)
        cout << b[j] << " \n"[j == n];
    return 0;
}