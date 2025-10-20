#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,k;
int a[maxn],b[maxn];
void solve()
{
    cin >> n >> k;
    bitset<maxn> b1,b2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b1[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b2[i] = 1;
    }
    int cnt = 0;
    for (int dlt = 0; dlt < n; dlt++)
    {
        bitset tmp = b1 & b2;
        for (int i = tmp._Find_first(); i != maxn; i = tmp._Find_next(i))
        {
            int &x = a[(i - dlt + n) % n],&y = b[i];
            if (x > y)
            {
                x -= y;
                y = 0;
                b2[i] = 0;
            }
            else
            {
                y -= x;
                x = 0;
                b1[i] = 0;
                cnt++;
            }
        }
        if (cnt == n)
        {
            cout << dlt + 1 << '\n';
            return;
        }
        b1 <<= 1;
        b1[0] = b1[n];
        b1[n] = 0;
    }
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