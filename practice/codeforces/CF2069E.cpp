#include<bits/extc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n,a,b,c,d;
char s[maxn];
void solve()
{
    scanf("%s%d%d%d%d",s + 1,&a,&b,&c,&d);
    n = strlen(s + 1);
    int cnta = 0,cntb = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'A')
            cnta++;
        else
            cntb++;
    }
    int need = max(cnta - a,cntb - b);
    int lst = 1,cnt = 0;
    vector<int>p1,p2;
    for (int i = 1; i <= n; i++)
    {
        if (i == n || s[i] == s[i + 1])
        {
            int len = (i - lst + 1) >> 1;
            if (!len)
                goto ed;
            if (s[lst] == s[i])
                cnt += len;
            else if (s[lst] == 'A')
                p1.push_back(len);
            else
                p2.push_back(len);
            ed:lst = i + 1;
        }
    }
    sort(p1.begin(),p1.end());
    sort(p2.begin(),p2.end());
    for (auto i : p1)
    {
        if (i <= c)
        {
            c -= i;
            need -= i;
        }
        else
            cnt += i - 1;
    }
    for (auto i : p2)
    {
        if (i <= d)
        {
            d -= i;
            need -= i;
        }
        else
        {
            need -= d;
            i -= d;
            d = 0;
            cnt += i - 1;
        }
    }
    if (need <= min(c + d,cnt))
        puts("YES");
    else
        puts("NO");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}