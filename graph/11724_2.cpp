#include <iostream>
using namespace std;

int graph[1001][1001] = {0};
int visited[1001] = {0};
int n;

void dfs(int s){
	if (visited[s]) return;
	visited[s] = 1;
	for (int i = 1; i <= n; i++){
		if (graph[s][i] == 1 &&!visited[i]){
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
}
