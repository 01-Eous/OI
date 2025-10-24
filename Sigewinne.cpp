#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, deg[N], a[N], tot = 0;
bool vis[N][N];
vector<int> g[N];
queue<int> q;
long long dp[N], ans = 0;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, x, y; i <= m; i++)
	{
		cin >> x >> y;
		if (x > y)
			swap(x, y);
		vis[x][y] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if (vis[i][j])
				g[j].push_back(i), deg[i]++;
			else
				g[i].push_back(j), deg[j]++;
		}
	for (int i = 1; i <= n; i++)
		if (!deg[i])
			q.push(i);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		a[u] = ++tot;
		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i];
			deg[v]--;
			if (!deg[v])
				q.push(v);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " \n"[i == n];
	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1, cnt = 0; j >= 1; j--)
			if (a[j] < a[i] && a[j] > cnt)
				dp[i] += dp[j], cnt = a[j];
		if (!dp[i])
			dp[i] = 1;
	}
	int cnt = 0;
	for (int i = n; i >= 1; i--)
		if (a[i] > cnt)
			cnt = a[i], ans += dp[i];
	cout << ans;
	return 0;
}