#include<bits/extc++.h>
using namespace std;
typedef double ld;
const ld eps = 1e-9;
int n;
char s[2005];
int cnt[2005];
ld a[2005][2005],ans[2005];
signed main()
{
    scanf("%s",s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        cnt[s[i] - 'A']++;
    a[n][n] = 1,ans[n] = 0;
    for (int i = 1; i < n; i++)
    {
        a[i][i - 1] = ld(i - 1) / (2 * i);
        a[i][i + 1] = ld(i + 1) / (2 * i);
        a[i][i] = -1,ans[i] = -(ld)n * (n - 1) / (2 * i * (n - i));
    }
    for (int i = 1; i < n; i++)
    {
        if (fabs(a[i + 1][i]) < eps)
            continue;
        ld tmp = a[i + 1][i] / a[i][i];
        for (int j = i; j <= n; j++)
            a[i + 1][j] -= tmp * a[i][j];
        ans[i + 1] -= tmp * ans[i];
    }
    for (int i = n; i > 1; i--)
    {
        if (fabs(a[i - 1][i]) < eps)
            continue;
        ld tmp = a[i - 1][i] / a[i][i];
        for (int j = i;  j <= n; j++)
            a[i - 1][j] -= tmp * a[i][j];
        ans[i - 1] -= tmp * ans[i];
    }
    ld Ans = 0;
    for (int i = 0; i < 26; i++)
        if (cnt[i])
            Ans += (ld)cnt[i] / n * ans[cnt[i]] / a[cnt[i]][cnt[i]];
    printf("%.1lf",Ans);
    return 0;
}