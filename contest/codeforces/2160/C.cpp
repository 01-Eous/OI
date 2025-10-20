#include<bits/extc++.h>
using namespace std;
int n;
basic_string<bool> vec;
bool chk()
{
    if ((vec.size() & 1) && vec[vec.size() >> 1])
        return 0;
    basic_string<bool> tmp = vec;
    reverse(tmp.begin(),tmp.end());
    return tmp == vec;
}
void solve()
{
    cin >> n;
    vec.clear();
    while (n)
    {
        vec.push_back(n & 1);
        n >>= 1;
    }
    while (vec.size() <= 64)
    {
        if (chk())
            return cout << "YES\n",void();
        vec.push_back(0);
    }
    cout << "NO\n";
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