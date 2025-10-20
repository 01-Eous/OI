#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e7 + 5;
const int mod = 998244353,inv2 = 499122177;
int n,idx;
bool vis[maxn];
int pr[maxn],phi[maxn];
__gnu_pbds::gp_hash_table<int,int> mem;
class mat
{
    public:
    int d[3][3];
    mat(int x = 0)
    {
        memset(d,0,sizeof(d));
        d[0][0] = d[1][1] = d[2][2] = x;
    }
    friend mat operator+(const mat &x,const mat &y)
    {
        mat res(0);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                res.d[i][j] = (x.d[i][j] + y.d[i][j]) % mod;
        return res;
    }
    friend mat operator*(const mat &x,const mat &y)
    {
        mat res(0);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    res.d[i][j] = (res.d[i][j] + x.d[i][k] * y.d[k][j]) % mod;
        return res;
    }
}base,ori,lst;
void init(int n = 2e7)
{
    base.d[0][0] = base.d[0][1] = base.d[1][0] =
    base.d[2][0] = base.d[2][2] = ori.d[0][0] = 1;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[++idx] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0)
            {
                phi[i * pr[j]] = phi[i] * pr[j];
                break;
            }
            phi[i * pr[j]] = phi[i] * phi[pr[j]];
        }
    }
    for (int i = 1; i <= n; i++)
        phi[i] = (phi[i] + phi[i - 1]) % mod;
}
mat binpow(mat x,int y)
{
    mat res(1);
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x;
        x = x * x;
    }
    return res;
}
int sumPhi(int n)
{
    if (n <= 2e7)
        return phi[n];
    if (mem.find(n) != mem.end())
        return mem[n];
    int res = (n % mod) * ((n + 1) % mod) % mod * inv2 % mod;
    for (int l = 2,r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        res = (res - ((r - l + 1) % mod) * sumPhi(n / l) % mod + mod) % mod;
    }
    return mem[n] = res;
}
int f(int x){return ((sumPhi(x) << 1) + mod - 1) % mod;}
int sumFib(int n){return (binpow(base,n) * ori).d[2][0];}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n,init();
    lst = mat(1);
    int ans = 0;
    for (int l = 1,r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        int suml = (lst * ori).d[2][0];
        lst = lst * binpow(base,r - l + 1);
        int sumr = (lst * ori).d[2][0];
        ans = (ans + (sumr - suml + mod) % mod * f(n / l)) % mod;
    }
    cout << ans << '\n';
    return 0;
}