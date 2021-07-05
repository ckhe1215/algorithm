#include <iostream>

using namespace std;

int graph[1001][1001] = {0};
int visited[1001] = {0};

void dfs(int start, int n) {
	if (visited[start] == 1 ) return;
	visited[start] = 1;
	for (int i = 1; i <= n; i++) {
		if (graph[start][i] == 1)
			dfs(i, n);
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0){
			dfs(i, n);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
