#include<bits/extc++.h>
using namespace std;
using ull = unsigned long long;
const int maxn = 2e6 + 5;
const ull base = 179;
int n,len,ans;
char s[maxn];
ull pw[maxn];
signed main()
{
    scanf("%d%s",&n,s + 1);
    if (!(n & 1))
        return puts("NOT POSSIBLE"),0;
    len = n >> 1;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * base;
    ull hsh1 = 0,hsh2 = 0,ans1 = 0,ans2 = 0;
    for (int i = 1; i <= len; i++)
    {
        hsh1 += pw[i] * (s[1 + i] - 'A');
        hsh2 += pw[i] * (s[1 + len + i] - 'A');
    }
    if (hsh1 == hsh2)
    {
        ans = 1;
        ans1 = hsh1,ans2 = hsh2;
    }
    for (int i = 1,j = 2,k = 1; k <= len; i++,j++,k++)
    {
        hsh1 -= pw[k] * (s[j] - 'A');
        hsh1 += pw[k] * (s[i] - 'A');
        if (hsh1 == hsh2)
        {
            if (!ans)
            {
                ans = j;
                ans1 = hsh1,ans2 = hsh2;
            }
            else if (hsh1 != ans1 || hsh2 != ans2)
                return puts("NOT UNIQUE"),0;
        }
    }
    for (int i = len + 1,j = len + 2,k = 1; k <= len; i++,j++,k++)
    {
        hsh2 -= pw[k] * (s[j] - 'A');
        hsh2 += pw[k] * (s[i] - 'A');
        if (hsh1 == hsh2)
        {
            if (!ans)
            {
                ans = j;
                ans1 = hsh1,ans2 = hsh2;
            }
            else if (hsh1 != ans1 || hsh2 != ans2)
                return puts("NOT UNIQUE"),0;
        }
    }
    if (!ans)
        return puts("NOT POSSIBLE"),0;
    for (int i = 1; len; i++)
    {
        if (i == ans)
            continue;
        putchar(s[i]);
        len--;
    }
    return 0;
}