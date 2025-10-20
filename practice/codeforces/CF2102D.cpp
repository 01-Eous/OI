#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn],b[maxn],tree[maxn];
int lowbit(int x){return x & -x;}
void upd(int i)
{
    for (; i; i -= lowbit(i))
        tree[i]++;
}
int que(int i)
{
    int res = 0;
    for (; i <= n; i += lowbit(i))
        res += tree[i];
    return res;
}
int calc(int *a)
{
    memset(tree,0,sizeof(int) * (n + 5));
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += que(a[i]),upd(a[i]);
    return res;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int cnt1 = calc(a);
    vector<int> vec[2];
    for (int i = 1; i <= n; i++)
        vec[i & 1].push_back(a[i]);
    sort(vec[0].begin(),vec[0].end());
    sort(vec[1].begin(),vec[1].end());
    for (int i = n; i >= 1; i--)
    {
        b[i] = vec[i & 1].back();
        vec[i & 1].pop_back();
    }
    int cnt2 = calc(b);
    if ((cnt1 & 1) != (cnt2 & 1))
        swap(b[n],b[n - 2]);
    for (int i = 1; i <= n; i++)
        cout << b[i] << " \n"[i == n];
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