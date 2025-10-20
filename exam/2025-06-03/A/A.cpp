//  做法：一眼   代码：亿眼
#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e6 + 5;
const int mod = 998244353;
int n;
char s[maxn];
signed main()
{
    scanf("%s",s + 1);
    n = strlen(s + 1);
    int pos = 1,ans = 0;
    while (s[pos] == 'B')
        pos++;
    for (int i = pos + 1; i <= n; i++)
    {
        if (s[i] != 'B')
        {
            if (s[i] != s[pos])
                ans = (ans + pos * (n - i + 1) % mod) % mod;
            pos = i;
        }
    }
    printf("%lld",ans);
    return 0;
}