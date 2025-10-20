#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n;
int cnt[26];
char s[maxn];
signed main()
{
    scanf("%lld%s",&n,s + 1);
    int pos = 1,ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (++cnt[s[i] - 'a'] > 1)
            while (cnt[s[i] - 'a'] > 1)
                cnt[s[pos++] - 'a']--;
        ans += i - pos + 1;
    }
    printf("%lld",ans);
    return 0;
}