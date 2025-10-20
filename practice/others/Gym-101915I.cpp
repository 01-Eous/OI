#include<bits/extc++.h>
#define endl '\n'
#define lowbit(x) (x & (-x))
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int id[maxn];
bool apr[maxn];
int tree1[maxn],tree2[maxn];
string a[maxn],b[maxn],c[maxn];
void upd(int *tree,int i,int x)
{
    for (; i <= 1e5; i += lowbit(i))
        tree[i] = max(tree[i],x);
}
int que(int *tree,int i)
{
    int ret = 0;
    for (; i; i -= lowbit(i))
        ret = max(ret,tree[i]);
    return ret;
}
void solve()
{
    cin >> n;
    memset(tree1,0,sizeof tree1);
    memset(tree2,0,sizeof tree2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        apr[i] = ((int)a[i].find('m') != -1);
        b[i] = a[i];
        reverse(b[i].begin(),b[i].end());
        c[i] = b[i];
    }
    sort(c + 1,c + n + 1);
    int m = unique(c + 1,c + n + 1) - c - 1;
    for (int i = 1; i <= n; i++)
        id[i] = lower_bound(c + 1,c + m + 1,b[i]) - c + 1;
    int ans = 0;
    for (int i = 1,tmp; i <= n; i++)
    {
        if (apr[i])
        {
            tmp = que(tree1,id[i]);
            ans = max(ans,tmp + 1);
            upd(tree2,id[i],tmp + 1);
        }
        else
        {
            tmp = que(tree2,id[i]);
            ans = max(ans,tmp + 1);
            upd(tree1,id[i],tmp + 1);
        }
    }
    cout << ans << endl;
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