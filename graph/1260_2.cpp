#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001] = {0};
int visited[1001] = {0};
queue<int> q;
int n;

void dfs(int s){
	cout << s << " ";
	visited[s] = 1;
	for(int i = 1; i <= n; i++){
		if (graph[s][i] == 1 && !visited[i])
			dfs(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	dfs(v);
	cout << "\n";
	for(int i = 0; i <= n; i++)
		visited[i] = 0;

	q.push(v);
	while (!q.empty()){
		int a = q.front();
		cout << a << " ";
		visited[a] = 1;
		q.pop();
		for(int i = 1; i <= n; i++)
			if (graph[a][i] == 1 && !visited[i]){
				q.push(i);
				visited[i] = 1;
			}
	}
}
