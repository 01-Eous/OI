#include<bits/extc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC target("avx")
using namespace std;
const int maxn = 3e5 + 5;
int n,a[maxn],f1[maxn][35],f2[maxn][35];
void read(int &x)
{
    int f = 1; x = 0;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
int que1(int l,int r)
{
    int k = __lg(r - l + 1);
    return max(f1[l][k],f1[r - (1 << k) + 1][k]);
}
int que2(int l,int r)
{
    int k = __lg(r - l + 1);
    return min(f2[l][k],f2[r - (1 << k) + 1][k]);
}
signed main()
{
    read(n);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        f1[i][0] = f2[i][0] = a[i];
    }
    for (int j = 1; j < 30; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            f1[i][j] = max(f1[i][j - 1],f1[i + (1 << (j - 1))][j - 1]);
            f2[i][j] = min(f2[i][j - 1],f2[i + (1 << (j - 1))][j - 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            ans = max(ans,que1(j,i) ^ que2(j,i));
    cout << ans;
    return 0;
}