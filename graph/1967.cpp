#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> tree[10001];
int visited[10001] = {0};
int total = 0;
int en;

void dfs(int n, int len)
{
	visited[n] = 1;
	if (len > total)
	{
		total = len;
		en = n;
	}
	for (int i = 0; i < tree[n].size(); i++)
	{
		int next = tree[n][i].first;
		int dist = tree[n][i].second;
		if (!visited[next])
			dfs(next, len + dist);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
	}

	dfs(1, 0);
	total = 0;
	for (int i = 0; i <= n; i++)
		visited[i] = 0;
	dfs(en, 0);
	cout << total;
}
