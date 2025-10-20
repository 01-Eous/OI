#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 10007;
int a,b,k,n,m;
int c[1005][1005];
signed main()
{
    cin >> a >> b >> k >> n >> m;
    a %= mod,b %= mod,c[1][1] = 1;
    for (int i = 2; i <= k + 1; i++)
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] * a + c[i - 1][j - 1] * b) % mod;
    cout << c[k + 1][m + 1];
    return 0;
}