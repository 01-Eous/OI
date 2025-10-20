#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int l,r;
int ans[maxn];
bool ipr[maxn];
vector<int> pr;
void prime(int up = 1e6)
{
    fill(ipr + 2,ipr + up + 1,1);
    for (int i = 2; i <= up; i++)
    {
        if (ipr[i])
            pr.push_back(i);
        for (auto j : pr)
        {
            if (i * j > up)
                break;
            ipr[i * j] = 0;
            if (i % j == 0)
                break;
        }
    }
}
signed main()
{
    prime();
    scanf("%lld%lld",&l,&r);
    for (auto i : pr)
    {
        int st = (l + i - 1) / i * i;
        assert(st >= l && st % i == 0);
        for (int j = st; j <= r; j += i)
            if (!ans[j - l])
                ans[j - l] = i;
    }
    for (int i = l; i <= r; i++)
        printf("%lld\n",ans[i - l] ? ans[i - l] : i);
    return 0;
}