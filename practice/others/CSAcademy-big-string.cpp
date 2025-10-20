#include<bits/extc++.h>
#define int long long
using namespace std;
int k;
string a,b;
int cnt[26];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> k;
    b = a.substr(0,a.size() - 1);
    reverse(b.begin(),b.end());
    a += b,k--;
    for (auto i : a)
        cnt[i - 'a']++;
    while (k--)
    {
        for (int i = 0; i < 26; i++)
        {
            if (i + 'a' != a[0])
                cnt[i] <<= 1;
            else
                cnt[i] = (cnt[i] << 1) - 1;
        }
    }
    for (int i = 0; i < 26; i++)
        cout << cnt[i] << ' ';
    return 0;
}