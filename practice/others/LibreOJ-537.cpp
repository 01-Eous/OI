#include<bits/extc++.h>
using namespace std;
const int maxn = 5e6 + 5;
int n,k;
char s[maxn];
unordered_map<int,int> cnt;
int id(char ch)
{
    if (ch == 'A')
        return 0;
    if (ch == 'G')
        return 1;
    if (ch == 'C')
        return 2;
    return 3;
}
signed main()
{
    scanf("%s%d",s + 1,&k);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        int hsh = 0;
        for (int j = i; j - i + 1 <= k; j++)
            hsh = hsh * 4 + id(s[j]);
        cnt[hsh]++;
    }
    int ans = 0;
    for (auto [x,y] : cnt)
        ans = max(ans,y);
    printf("%d",ans);
    return 0;
}