#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
int cnt[8];
char s[] = "iamhuman";
signed main()
{
    scanf("%lld",&n);
    fill(cnt,cnt + 8,1);
    int tmp = 1,p = 0;
    while (tmp < n)
    {
        tmp /= cnt[p];
        cnt[p]++;
        tmp *= cnt[p];
        p = (p + 1) % 8;
    }
    for (int i = 0; i < 8; i++)
        while (cnt[i]--)
            putchar(s[i]);
    return 0;
}