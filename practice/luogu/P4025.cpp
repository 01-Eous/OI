#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,h;
struct Klee{int d,a,id;}tmp;
vector<Klee> a,b;
bool cmp1(const Klee &x,const Klee &y){return x.d < y.d;}
bool cmp2(const Klee &x,const Klee &y){return x.a > y.a;}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> h;
    for (int i = 1; i <= n; i++)
    {
        tmp.id = i;
        cin >> tmp.d >> tmp.a;
        if (tmp.d <= tmp.a)
            a.push_back(tmp);
        else
            b.push_back(tmp);
    }
    sort(a.begin(),a.end(),cmp1);
    for (auto [d,a,id] : a)
    {
        if (h <= d)
            return cout << "NIE",0;
        h += a - d;
    }
    sort(b.begin(),b.end(),cmp2);
    for (auto [d,a,id] : b)
    {
        if (h <= d)
            return cout << "NIE",0;
        h += a - d;
    }
    if (h <= 0)
        return cout << "NIE",0;
    cout << "TAK\n";
    for (auto [d,a,id] : a)
        cout << id << ' ';
    for (auto [d,a,id] : b)
        cout << id << ' ';
    return 0;
}