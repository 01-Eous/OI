#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
int n;
int a[maxn];
class two_set
{
    private:
    multiset<int,less<>> mx;// 小根堆维护最大的几个数
    multiset<int,greater<>> mi;// 大根堆维护最小的几个数。
    void balance()
    {
        if (mx.size() > mi.size() + 1)
        {
            _min += *mx.begin();
            _max -= *mx.begin();
            mi.insert(*mx.begin());
            mx.erase(mx.begin());
        }
        if (mi.size() > mx.size())
        {
            _max += *mi.begin();
            _min -= *mi.begin();
            mx.insert(*mi.begin());
            mi.erase(mi.begin());
        }
    }
    public:
    int _min,_max;// 分别表示最小的数的和，最大的数的和。
    void insert(int x)
    {
        if (mx.empty() || x >= *mx.begin())
        {
            _max += x;
            mx.insert(x);
        }
        else
        {
            _min += x;
            mi.insert(x);
        }
        balance();
    }
    void erase(int x)
    {
        auto it = mx.find(x);
        if (it != mx.end())
        {
            _max -= x;
            mx.erase(it);
        }
        else
        {
            _min -= x;
            it = mi.find(x);
            assert(it != mi.end());
            mi.erase(it);
        }
        balance();
    }
}s1,s2;
void solve1()
{
    for (int i = 1; i <= n; i++)
        s2.insert(a[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        s2.erase(a[i]);
        if (i & 1)
            ans = max(ans,s1._max - s1._min + s2._max - s2._min);
        s1.insert(a[i]);
    }
    printf("%lld",ans);
}
void solve2()
{
    sort(a + 1,a + n + 1);
    int _max = 0,_min = 0;
    for (int i = 1; i <= n >> 1; i++)
        _min += a[i];
    for (int i = (n >> 1) + 1; i <= n; i++)
        _max += a[i];
    printf("%lld",_max - _min);
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    if (n & 1)
        solve1();
    else
        solve2();
    return 0;
}