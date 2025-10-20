#include<bits/extc++.h>
using namespace std;
const int maxn = 160005;
int n,m;
int a[405][405];
int dp[405][405][405],cnt[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int len = 1; len <= m; len++)
    {
        for (int i = 1,j; (j = i + len - 1) <= m; i++)
        {
            int pos = 1;
            for (int k = 1; k <= n; k++)
            {
                if (len == 1)
                {
                    cnt[a[k][i]]++; 
                    while (cnt[a[k][i]] > 1)
                        cnt[a[pos][i]]--,pos++;
                }
                else
                {
                    cnt[a[k][i]]++,cnt[a[k][j]]++;
                    while (cnt[a[k][i]] > 1 || cnt[a[k][j]] > 1)
                        cnt[a[pos][i]]--,cnt[a[pos][j]]--,pos++;
                }
                dp[i][j][k] = max({dp[i + 1][j][k],dp[i][j - 1][k],pos});
                ans = max(ans,len * (k - dp[i][j][k] + 1));
            }
            for (int k = 1; k <= n; k++)
                cnt[a[k][i]] = cnt[a[k][j]] = 0;
        }
    }
    printf("%d",ans);
    return 0;
}