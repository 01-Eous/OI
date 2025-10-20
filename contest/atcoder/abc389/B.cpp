#include<bits/extc++.h>
using namespace std;
long long fac = 1;
long long x;
signed main()
{
    cin >> x;
    for (int i = 1; i <= 1e5; i++)
    {
        fac *= i;
        if (fac == x)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}