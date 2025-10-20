#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define eps 1e-8
using namespace std;
const int maxn = 5e5 + 5,inf = 1e18;
int n,t[maxn],f[maxn];
int dp[maxn],q[maxn],head,tail;
inline void read(int &x)
{
    x = 0; int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}
inline int x(int j){return t[j];}
inline int k(int i){return -t[i];}
inline int y(int j){return dp[j] / 2 - f[j];}
inline double slope(int i,int j){return double(y(j) - y(i)) / double(x(j) - x(i));}
signed main()
{
    read(n);
    for (int i = 1; i <= n; i++)
        read(t[i]);
    for (int i = 1; i <= n; i++)
        read(f[i]);
    dp[1] = 0;
    head = tail = 1;
    q[1] = 1;
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        while (head < tail && slope(q[head],q[head + 1]) >= k(i))
            head++;
        int j = q[head];
        dp[i] = dp[j] / 2 - f[j] + t[i] * t[j];
        ans = max(ans,dp[i]);
        while (head < tail && slope(q[tail - 1],q[tail]) < slope(q[tail],i))
            tail--;
        q[++tail] = i;
    }
    printf("%lld",ans);
    return 0;
}