#include<bits/extc++.h>
#define sq(x) ((x) * (x))
using namespace std;
typedef double ld;
const int maxn = 3e5 + 5;
int n;
ld dp[maxn],len;
char s[maxn];
signed main()
{
    scanf("%d%s",&n,s + 1);
    dp[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        if (s[i] == 'o')
            dp[i] = dp[i + 1] + sq(len + 1) - sq(len),len += 1;
        else if (s[i] == 'x')
            dp[i] = dp[i + 1],len = 0;
        else
        {
            dp[i] = dp[i + 1] + (sq(len + 1) - sq(len) + 0) / 2.0;
            len = (len + 1 + 0) / 2.0;
        }
    }
    printf("%.4lf",dp[1]);
    return 0;
}