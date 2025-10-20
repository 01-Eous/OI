#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,q;
int suma,sumb;
set<int> a,b;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x,suma += x;
        a.insert(x);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x,sumb += x;
        b.insert(x);
    }
    while (q--)
    {
        cin >> x;
        bool fl = 0;
        for (int i = 1; i * i <= abs(x); i++)
        {
            if (abs(x) % i)
                continue;
            int u = i,v = x / i;
            if ((a.count(suma - u) && b.count(sumb - v)) || (a.count(suma - v) && b.count(sumb - u)))
            {
                cout << "YES\n",fl = 1;
                break;
            }
            u = -u,v = -v;
            if ((a.count(suma - u) && b.count(sumb - v)) || (a.count(suma - v) && b.count(sumb - u)))
            {
                cout << "YES\n",fl = 1;
                break;
            }
        }
        if (!fl)
            cout << "NO\n";
    }
    return 0;
}