#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 2e5 + 5;
int n;
int a[maxn],b[maxn];
pii tree[maxn << 1];
int cnt[3],sum[maxn][3];
pii &operator+=(pii &x,const pii &y)
{
    x.first += y.first;
    x.second += y.second;
    return x;
}
inline int lowbit(int x){return x & -x;}
inline void upd(int x)
{
    for (int i = x + n; i <= n << 1; i += lowbit(i))
        tree[i] += {1,x};
}
inline pii que(int x)
{
    pii res = {0,0};
    for (int i = x + n; i; i -= lowbit(i))
        res += tree[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    char ch;
    for (int i = 1; i <= n; i++)
    {
        cin >> ch;
        if (ch == 'a')
            a[i] = 0;
        else if (ch == 'b')
            a[i] = 1;
        else
            a[i] = 2;
        memcpy(sum[i],sum[i - 1],sizeof(sum[i]));
        sum[i][a[i]]++;
    }
    int ans = 0,sna = 0;
    for (int s = 0; s < 3; s++)
    {
        int x = (s + 1) % 3,y = (x + 1) % 3;
        for (int i = 1,j; i <= n; i++)
        {
            if (a[i] == s)
                continue;
            j = i;
            while (j < n && a[j + 1] != s)
                j++;
            for (int k = i - 1; k <= j; k++)
                b[k] = sum[k][x] - sum[k][y];
            sort(b + i - 1,b + j + 1);
            for (int k = i - 1; k <= j; k++)
                ans += b[k] * (k - i + 1) - b[k] * (j - k);
            int len = 0;
            for (int k = i; k <= j; k++)
            {
                if (a[k] != a[k - 1])
                    len = 0;
                len++;
                ans -= len * (len + 1) >> 1;
            }
            i = j;
        }
        memset(cnt,0,sizeof(cnt));
        memset(tree,0,sizeof(pii) * ((n << 1) + 5));
        int res = 0;
        for (int i = 1,j = 0; i <= n; i++)
        {
            cnt[a[i]]++;
            while (cnt[0] && cnt[1] && cnt[2])
            {
                int tmp = sum[j][x] - sum[j][y];
                res += tmp,upd(tmp),cnt[a[++j]]--;
            }
            int val = sum[i][x] - sum[i][y];
            pii tmp = que(val);
            sna += tmp.first * val - tmp.second + res - tmp.second - (j - tmp.first) * val;
        }
    }
    cout << ans + (sna >> 1) << '\n';
    return 0;
}