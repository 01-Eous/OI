#include<bits/extc++.h>
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e4 + 5;
int n,m;
pii a[maxn];
char s[maxn];
bool mp[15][maxn];
int x[15],tmp[maxn],ans[maxn];
inline int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
inline int calc()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= m; j++)
            sum += tmp[j] * mp[i][j];
        res += abs(x[i] - sum);
    }
    return res;
}
inline void solve()
{
    n = read(),m = read();
    for (int i = 1; i <= n; i++)
        x[i] = read();
    for (int i = 1; i <= n; i++)
    {
        scanf("%s",s + 1);
        for (int j = 1; j <= m; j++)
            mp[i][j] = s[j] == '1';
    }
    int max1 = -1;
    for (int s = 0; s < 1 << n; s++)
    {
        for (int i = 1; i <= m; i++)
        {
            a[i] = {0,i};
            for (int j = 1; j <= n; j++)
                a[i].first += mp[j][i] * (s >> (j - 1) & 1 ? 1 : -1);
        }
        sort(a + 1,a + m + 1);
        for (int i = 1; i <= m; i++)
            tmp[a[i].second] = i;
        if (int x = calc(); x > max1)
        {
            max1 = x;
            memcpy(ans,tmp,sizeof(int) * (m + 5));
        }
    }
    for (int i = 1; i <= m; i++)
        printf("%d%c",ans[i]," \n"[i == m]);
}
signed main()
{
    int t = read();
    while (t--)
        solve();
    return 0;
}