#include<bits/extc++.h>
#define int long long
using namespace std;
int n,k,up;
__int128 mul = 1;
signed main()
{
    cin >> n >> k;
    up = pow(10,k);
    int x;
    while (n--)
    {
        cin >> x;
        mul *= x;
        if (mul >= up)
            mul = 1;
    }
    cout << (int)mul;
    return 0;
}