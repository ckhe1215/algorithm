#include <iostream>
#include <queue>

using namespace std;

int n, m, v;
int map[1001][1001] = {0};
int visited[1001] = {0};
int visited2[1001] = {0};

void dfs(int v)
{
	if(visited[v]) return;
	visited[v] = 1;
	cout << v << ' ';
	for(int i = 0; i <= n; i++)
	{
		if (map[v][i] == 1 && !visited[i])
			dfs(i);
	}
}

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	visited2[v] = 1;
	while (!q.empty()) {
		for (int i = 0; i <= n; i++){
			if (map[v][i] == 1 && !visited2[i])
			{
				q.push(i);
				visited2[i] = 1;
			}
		}
		cout << v << ' ';
		q.pop();
		v = q.front();
	}
}

int main()
{
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	dfs(v);
	cout << "\n";
	bfs(v);
	return 0;
}
