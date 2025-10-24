#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], sum[N][3], b[N], ans, sna, cnt[3], d1[N << 1], d2[N << 1];
char ch;
void clear()
{
    for (int i = 1; i <= n << 1; i++)
        d1[i] = d2[i] = 0;
}
void upd(int x)
{
    for (int i = x + n; i <= n << 1; i += i & -i)
        d1[i]++, d2[i] += x;
}
pii que(int i)
{
    pii res = {0, 0};
    for (i += n; i >= 1; i -= i & -i)
        res.first += d1[i], res.second += d2[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ch;
        a[i] = ch == 'a' ? 0 : ch == 'b' ? 1
                                         : 2;
        for (int j : {0, 1, 2})
            sum[i][j] = sum[i - 1][j];
        sum[i][a[i]]++;
    }
    for (int s = 0; s <= 2; s++)
    {
        int x = (s + 1) % 3, y = (x + 1) % 3;
        for (int i = 1; i <= n;)
        {
            if (a[i] == s)
            {
                i++;
                continue;
            }
            int j = i;
            while (j < n && a[j + 1] != s)
                j++;
            for (int k = i - 1; k <= j; k++)
                b[k] = sum[k][x] - sum[k][y];
            sort(b + i - 1, b + j + 1);
            int cnt = 0;
            for (int k = i; k <= j; k++)
            {
                cnt++;
                ans -= cnt * (cnt + 1) / 2;
                if (k < j && a[k + 1] != a[k])
                    cnt = 0;
            }
            for (int k = i - 1; k <= j; k++)
                ans += b[k] * (k - (i - 1)) - b[k] * (j - k);
            i = j + 1;
        }
        cnt[0] = cnt[1] = cnt[2] = 0;
        clear();
        int res = 0;
        for (int i = 1, j = 0; i <= n; i++)
        {
            cnt[a[i]]++;
            while (cnt[0] && cnt[1] && cnt[2])
            {
                res += sum[j][x] - sum[j][y];
                upd(sum[j][x] - sum[j][y]);
                cnt[a[++j]]--;
            }
            int val = sum[i][x] - sum[i][y];
            pii tmp = que(val);
            sna += tmp.first * val - tmp.second + res - tmp.second - (j - tmp.first) * val;
        }
    }
    cout << ans + sna / 2 << endl;
    return 0;
}