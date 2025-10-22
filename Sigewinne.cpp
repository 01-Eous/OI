#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;

const int N = 1e5 + 5;
int n, f, h;
vector <P> vec;
int ans, res[N];
int cannot[4][N];
vector <int> edge[N];

int cur(int u)
{
	return cannot[1][u] + cannot[2][u] + cannot[3][u];
}

void dfs(int u)
{
	int i;

	for(i = 1; i <= 3; i++)
	{
		if(!cannot[i][u])
		{
			res[u] = i;
			
			for(auto v : edge[u])
				cannot[i][v] = 1;
			for(auto v : edge[u])
			{
				if(res[v]) continue;
				if(cur(v) == 2) dfs(v);
			}
			for(auto v : edge[u])
			{
				if(res[v]) continue;
				dfs(v);
			}
			
			break;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	//freopen("fire.in", "r", stdin);
	freopen("fire.out", "w", stdout);
	
	int i, k;
	cin >> n;
	
	for(i = 1; i <= n; i++)
	{
		cin >> f >> h;
		
		if(f)
		{
			for(k = (int)(vec.size()) - 1; k >= 0; k--)
			{
				int &p = vec[k].fi;
				int &j = vec[k].se;
				edge[i].push_back(j);
				edge[j].push_back(i);
				cout << j << ' ' << i << endl;
				if(f > p)
				{
					f -= p;
					vec.pop_back(); 
				}
				else
				{
					p -= f, f = 0;
					if(p == 0) vec.pop_back();
					break;
				}
			}
		}
	
		if(h)
			vec.push_back(make_pair(h, i));
	}
	
	for(i = 1; i <= n; i++)
		if(!res[i])
			dfs(i);
	
	for(i = 1; i <= n; i++)
		ans = max(ans, res[i]);
	cout << ans << "\n";
	for(i = 1; i <= n; i++)
		cout << res[i] << " ";
	return 0;
}