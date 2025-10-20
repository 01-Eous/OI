#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,x;
int cnt[maxn];
bool ipr[maxn];
vector<int> pr,vec;
void prime(int n = 1e6)
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
            pr.push_back(i);
        for (auto j : pr)
        {
            if (i * j > n)
                break;
            ipr[i * j] = 1;
            if (i % j == 0)
                break;
        }
    }
    for (auto i : pr)
        for (int j = i; j <= n; j += i)
            cnt[j]++;
    for (int i = 1; i <= n; i++)
        if (cnt[i] == 2)
            vec.push_back(i * i);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    prime();
    cin >> n;
    int x;
    while (n--)
    {
        cin >> x;
        cout << *(upper_bound(vec.begin(),vec.end(),x) - 1) << '\n';
    }
    return 0;
}
