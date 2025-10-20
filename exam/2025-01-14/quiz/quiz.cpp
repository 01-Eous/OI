#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n;
int l[maxn],r[maxn],len[maxn];
priority_queue<int,vector<int>,less<int>>ql;
priority_queue<int,vector<int>,greater<int>>qr;
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld",l + i,r + i);
        len[i] = r[i] - l[i];
    }
    ql.push(l[1]);
    qr.push(l[1]);
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        static int pl = 0,pr = 0;
        pl -= len[i];
        pr += len[i - 1];
        int tmpl = ql.top() + pl;
        int tmpr = qr.top() + pr;
        if (l[i] < tmpl)
        {
            ans += tmpl - l[i];
            ql.pop();
            ql.push(l[i] - pl);
            ql.push(l[i] - pl);
            qr.push(tmpl - pr);
        }
        else if (l[i] > tmpr)
        {
            ans += l[i] - tmpr;
            qr.pop();
            qr.push(l[i] - pr);
            qr.push(l[i] - pr);
            ql.push(tmpr - pl);
        }
        else
        {
            ql.push(l[i] - pl);
            qr.push(l[i] - pr);
        }
    }
    printf("%lld",ans);
    return 0;
}