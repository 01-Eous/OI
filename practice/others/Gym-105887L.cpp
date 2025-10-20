#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;
int n,sum;
deque<int> stk;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string op;
    int x;
    while (n--)
    {
        cin >> op;
        if (op[1] == 'u')
        {
            cin >> x;
            stk.push_back(x);
            sum = (sum + x) % mod;
        }
        else if (op[1] == 'e')
        {
            int len = stk.size();
            for (int i = 1; i <= len && stk.size() < 2e5; i++)
                stk.push_front(stk[stk.size() - i]);
            sum = (sum << 1) % mod;
        }
        else
        {
            sum = (sum - stk.back() + mod) % mod;
            stk.pop_back();
        }
        while (stk.size() > 2e5)
            stk.pop_front();
        cout << sum << '\n';
    }
    return 0;
}