#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
using pii = pair<int,int>;
int n,m;
int a[maxn],cnt[maxn],buc[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        if (cin >> a[i]; a[i] <= m)
            buc[a[i]]++;
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m; j += i)
            cnt[j] += buc[i];
    int *pos = max_element(cnt + 1,cnt + m + 1);
    int val = pos - cnt;
    cout << val <<  ' ' << *pos << '\n';
    for (int i = 1; i <= n; i++)
        if (val % a[i] == 0)
            cout << i << ' ';
    return 0;
}