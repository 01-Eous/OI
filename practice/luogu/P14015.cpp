#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
int cnt[3];
char s[maxn];
void solve()
{
    scanf("%s",s + 1);
    n = strlen(s + 1);
    memset(cnt,0,sizeof(cnt));
    for (int i = 1; i <= n; i++)
    {
        if (s[i] != '2')
            cnt[(s[i] - '0') ^ (i & 1)]++;
        else
            cnt[2]++;
    }
    int tmp = abs(cnt[0] - cnt[1]);
    if (cnt[2] >= tmp)
        printf("%d\n",(cnt[2] + tmp) & 1);
    else
        printf("%d\n",tmp - cnt[2]);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}