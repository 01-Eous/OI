// 扫码出题人题意不写清楚还不给小样例
#include<bits/extc++.h>
#define int long long
#define chkmax(x,y) x = max(x,y)
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
char s[maxn];
int mp[26][26],max1[26],dp[maxn];
signed main()
{
    freopen("shiki.in","r",stdin);
    freopen("shiki.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> (s + 1) >> m;
    while (m--)
    {
        char a,b; int c;
        cin >> a >> b >> c;
        mp[a - 'a'][b - 'a'] += c;
    }
    memset(max1,~0x3f,sizeof(max1));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
            chkmax(dp[i],max1[j] + mp[j][s[i] - 'a']);
        chkmax(max1[s[i] - 'a'],dp[i]);
        chkmax(ans,dp[i]);
    }
    cout << ans;
    return 0;
}