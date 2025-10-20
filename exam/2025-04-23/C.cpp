#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 5e5 + 5;
int n,q,len;
int l[maxn],r[maxn];
int sum[maxn],x[maxn],tree[maxn];
map<pii,int> f;
vector<int> vec[maxn],que[maxn];
struct query
{
    int m;
    vector<int> x;
}a[maxn];
int lowbit(const int &x){return x & -x;}
void upd(int i,int x)
{
    for (; i; i -= lowbit(i))
        tree[i] += x;
}
int qry(int i)
{
    int res = 0;
    for (; i <= n; i += lowbit(i))
        res += tree[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    len = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        vec[l[i]].push_back(r[i]);        
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> a[i].m;
        a[i].x.resize(a[i].m + 5);
        for (int j = 1; j <= a[i].m; j++)
            cin >> x[j];
        sort(x + 1,x + a[i].m + 1);
        for (int j = 1; j <= a[i].m; j++)
            a[i].x[j] = x[j];
        if (a[i].m >= len)
            continue;
        for (int j = 1; j <= a[i].m; j++)
            for (int k = j; k <= a[i].m; k++)
                que[x[j]].push_back(x[k]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : vec[i])
            upd(j,1);
        for (auto j : que[i])
            f[{i,j}] = qry(j);
    }
    for (int i = 1; i <= q; i++)
    {
        int ans = 0;
        if (a[i].m >= len)
        {
            fill(sum + 1,sum + n + 1,0);
            for (int j = 1; j <= a[i].m; j++)
                sum[a[i].x[j]]++;
            for (int j = 1; j <= n; j++)
                sum[j] += sum[j - 1];
            for (int j = 1; j <= n; j++)
                ans += (sum[r[j]] - sum[l[j] - 1]) & 1;
            cout << ans << '\n';
            continue;
        }
        for (int j = 1; j <= a[i].m; j++)
        {
            ans += f[{a[i].x[j],a[i].x[j]}];
            for (int k = j + 1,op = -2; k <= a[i].m; k++,op = -op)
                ans += f[{a[i].x[j],a[i].x[k]}] * op;
        }
        cout << ans << '\n';
    }
    return 0;
}
