#include<bits/extc++.h>
using namespace std;
using pii = pair<int,int>;
int n;
vector<pii> ans;
void solve1()
{
    for (int x = 1,y = 1,_ = 1; _ <= n + 2; x++,y++,_++)
        ans.push_back({x,y});
    for (int x = 1,y = 2,_ = 1; _ <= n + 1; x++,y++,_++)
        ans.push_back({x,y});
    for (int x = 2,y = 1,_ = 1; _ <= n + 1; x++,y++,_++)
        ans.push_back({x,y});
}
void solve2()
{
    ans.push_back({1,2});
    ans.push_back({1,3});

    ans.push_back({2,1});
    ans.push_back({2,2});
    ans.push_back({2,3});
    ans.push_back({2,4});

    ans.push_back({3,1});
    ans.push_back({3,2});
    ans.push_back({3,3});
    ans.push_back({3,4});

    ans.push_back({4,2});
    ans.push_back({4,3});

    n -= 6;
    int x = 4,y = 3;
    for (; n; n -= 3,x++,y++)
    {
        ans.push_back({x + 1,y});
        ans.push_back({x + 1,y + 1});
        ans.push_back({x,y + 1});
        ans.push_back({x,y + 2});
        ans.push_back({x - 1,y + 2});
    }
    ans.push_back({x - 1,y + 2});
    ans.push_back({x - 1,y + 3});

    ans.push_back({x,y + 1});
    ans.push_back({x,y + 3});

    ans.push_back({x + 1,y});
    ans.push_back({x + 1,y + 3});

    ans.push_back({x + 2,y});
    ans.push_back({x + 2,y + 1});
    ans.push_back({x + 2,y + 2});
    ans.push_back({x + 2,y + 3});
}
signed main()
{
    scanf("%d",&n);
    if (n <= 298)
        solve1();
    else
        solve2();
    printf("%lld\n",ans.size());
    for (auto [x,y] : ans)
        printf("%d %d\n",x,y);
    return 0;
}