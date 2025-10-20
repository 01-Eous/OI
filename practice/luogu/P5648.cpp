#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n,q;
int stk[maxn],top;
int a[maxn],nxt[25][maxn],f[25][maxn];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
signed main()
{
    n = read(),q = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        while (top && a[stk[top]] < a[i])
            nxt[0][stk[top--]] = i;
        stk[++top] = i;
    }
    while (top)
        nxt[0][stk[top--]] = n + 2;
    nxt[0][n + 1] = nxt[0][n + 2] = n + 2;
    for (int i = 1; i <= n; i++)
        f[0][i] = a[i] * (nxt[0][i] - i);
    for (int i = 1; i <= 20; i++)
    {
        fill(nxt[i] + 1,nxt[i] + n + 3,n + 2);
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
            f[i][j] = f[i - 1][j] + f[i - 1][nxt[i - 1][j]];
        }
    }
    int l,r,lst = 0;
    while (q--)
    {
        l = (read() ^ lst) % n + 1;
        r = (read() ^ (lst + 1)) % (n - l + 1) + l;
        int ans = 0,pos = l;
        for (int i = 20; ~i; i--)
        {
            if (nxt[i][pos] > r + 1)
                continue;
            ans += f[i][pos];
            pos = nxt[i][pos];
        }
        ans += a[pos] * (r - pos + 1);
        printf("%lld\n",lst = ans);
    }
    return 0;
}