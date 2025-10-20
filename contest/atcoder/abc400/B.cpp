#include<bits/extc++.h>
#define ll long long
using namespace std;
int n,m,x;
signed main()
{
    cin >> n >> m;
    for (int i = 0; i <= m; i++)
    {
        ll tmp = pow(n,i);
        if (tmp + x > 1e9)
            return cout << "inf",0;
        x += tmp;
    }
    cout << x;
    return 0;
}