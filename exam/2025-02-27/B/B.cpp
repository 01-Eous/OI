//我们拥有分数 
#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
int n,k;
int p[maxn];
bool b[maxn];
vector<int>ans;
signed main()
{
    scanf("%lld%lld",&n,&k);
    if ((k << 1) > n)
        return printf("-1"),0;
    fill(b + 1,b + n + 1,1);
    for (int s = 1; s + (k << 1) - 1 <= n && ans.size() < n - (k << 1); s += (k << 1))
    {
        int t = s + (k << 1);
        for (int i = s + k; i < t && ans.size() < n - (k << 1); i++)
        {
            b[i] = 0;
            ans.push_back(i);
        }
        for (int i = s; i < s + k && ans.size() < n - (k << 1); i++)
        {
            b[i] = 0;
            ans.push_back(i);
        }
    }
    for (int i = n - k + 1; i <= n; i++)
    {
        b[i] = 0;
        ans.push_back(i);
    }
    for (int i = 1; i <= n; i++)
        if (b[i])
            ans.push_back(i);
    for (auto i : ans)
        printf("%lld ",i);
    return 0;
}
//10 3
 
