#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n;
bool ipr[maxn];
vector<int> pr;
void prime()
{
    memset(ipr,1,sizeof ipr);
    ipr[1] = 0;
    for (int i = 2; i <= 1e5; i++)
    {
        if (ipr[i])
            pr.push_back(i);
        for (auto j : pr)
        {
            if (i * j > 1e5)
                break;
            ipr[i * j] = 0;
            if (i % j == 0)
                break;
        }
    }
}
void solve()
{
    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp1 = (sum + *st.begin() - 1) / i + 1;
        while (!ipr[tmp1])
            tmp1++;
        int tmp2 = i * (tmp1 - 1) + 1 - sum;
        set<int>::iterator p = st.lower_bound(tmp2);
        if (p == st.end())
            p--;
        cout << *p << " \n"[i == n];
        sum += *p;
        st.erase(p);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    prime();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}