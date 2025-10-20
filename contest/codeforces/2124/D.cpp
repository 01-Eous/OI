#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,k,w;
void solve()
{
    cin >> n >> k;
    vector<int>a1(n),a2(n),b1,b2,cnt;
    for (int i = 0; i < n; i++)
        cin >> a1[i],a2[i] = a1[i];
    sort(a2.begin(),a2.end()),w = a2[k - 1];
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (a1[i] < w)
        {
            b1.push_back(a1[i]);
            cnt.push_back(tmp);
            tmp = 0;
        }
        else if (a1[i] == w)
            tmp++;
    }
    cnt.push_back(tmp);
    for (int i = 0,j = cnt.size() - 1; i < j; i++,j--)
        cnt[i] = cnt[j] = min(cnt[i],cnt[j]);

    b2 = b1,reverse(b2.begin(),b2.end());
    if (b1 != b2)
        return (void)(cout << "NO\n");

    tmp = 0;
    for (auto i : cnt)
        tmp += i;
    if (tmp + b1.size() < k - 1)
        return (void)(cout << "NO\n");

    cout << "YES\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}