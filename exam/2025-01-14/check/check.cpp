#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
string s,t;
int lens,lent;
int q,a,b,c,d;
int sum1[maxn],sum2[maxn];
signed main()
{
    cin >> s >> t;
    lens = s.length();
    lent = t.length();
    s = ' ' + s;
    t = ' ' + t;
    for (int i = 1; i <= lens; i++)
        sum1[i] = sum1[i - 1] + (s[i] == 'A' ? 1 : 2);
    for (int i = 1; i <= lent; i++)
        sum2[i] = sum2[i - 1] + (t[i] == 'A' ? 1 : 2);  
    scanf("%d",&q);
    while (q--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if ((sum1[b] - sum1[a - 1]) % 3 == (sum2[d] - sum2[c - 1]) % 3)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}