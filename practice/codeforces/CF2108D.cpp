#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n,k;
int mem[maxn];
deque<int> q;
basic_string<int> a,b;
int ask(int x)
{
    if (!mem[x])
    {
        cout << "? " << x << endl;
        cin >> mem[x];
    }
    return mem[x];
}
void solve()
{
    cin >> n >> k;
    memset(mem,0,sizeof(int) * (n + 5));
    if (n == k << 1)
    {
        cout << "! " << k << " " << k << endl;
        return;
    }
    a.clear(),b.clear();
    for (int i = 1; i <= k; i++)
        q.push_back(ask(i));
    while (!q.empty())
    {
        a.push_back(q.front());
        q.pop_front();
    }
    for (int i = 1; i <= k; i++)
        q.push_front(ask(n - i + 1));
    int tmp = n % k;
    while (tmp--)
    {
        q.push_front(q.back());
        q.pop_back();
    }
    while (!q.empty())
    {
        b.push_back(q.front());
        q.pop_front();
    }
    int pos = -1;
    for (int i = 0; i < k; i++)
    {
        if (a[i] != b[i])
        {
            pos = i;
            break;
        } 
    }
    if (!~pos)
    {
        cout << "! -1" << endl;
        return;
    }
    int l = 1,r = n / k,mid,res = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (ask(k * (mid - 1) + pos + 1) == a[pos])
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    int lst,p1 = 0,p2 = 0;
    lst = ask(k * (res - 1) + 1) == a.front();
    for (int i = k * (res - 1) + 2; i <= min(n,k * (res + 1)); i++)
    {
        int cur = ask(i) == a[(i - 1) % k];
        if (cur != lst)
        {
            p1 = i;
            break;
        }
        lst = cur;
    }
    lst = ask(min(n,k * (res + 1))) == b[(min(n,k * (res + 1)) - 1) % k];
    for (int i = min(n,k * (res + 1)) - 1; i > k * (res - 1); i--)
    {
        int cur = ask(i) == b[(i - 1) % k];
        if (cur != lst)
        {
            p2 = i;
            break;
        }
    }
    if (p1 > n - k + 1)
        p1 = n - k + 1;
    if (p2 < k)
        p2 = k;
    if (p1 - p2 != 1)
        cout << "! -1" << endl;
    else
        cout << "! " << p2 << ' ' << n - p2 << endl;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}