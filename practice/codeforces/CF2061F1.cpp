#include<bits/extc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int n;
char s1[maxn],s2[maxn];
void solve()
{
    scanf("%s%s",s1 + 1,s2 + 1);
    n = strlen(s1 + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s1[i] == s2[i])
            continue;
        if (s1[i] == s1[i - 1] && s2[i] != s2[i - 1])
            return (void)puts("-1");
        int j = i + 1,k = i + 1,tmp = 0,cnt = 0;
        while (j <= n && s2[j] == s2[i])
            j++;
        while (k <= n && cnt < j - i)
        {
            cnt += s1[k] == s2[i];
            if (s1[k] == s2[i] && s1[k - 1] != s2[i])
                tmp++;
            k++;
        }
        if (cnt < j - i)
            return (void)puts("-1");
        if (k <= n && s1[k] == s2[i])
            return (void)puts("-1");
        ans += tmp;
        for (int x = i; x < j; x++)
            s1[x] = s2[i];
        for (int x = j; x < k; x++)
            s1[x] = '0' + '1' - s2[i];
    }
    printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}