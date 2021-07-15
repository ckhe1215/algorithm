#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1000001];
int visited[1000001] = {0};
int parent[1000001] = {0};

void dfs(int r, int p) {
	visited[r] = 1;
	parent[r] = p;
	for (int i = 0; i < graph[r].size(); i++) {
		if (!visited[graph[r][i]])
			dfs(graph[r][i], r);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, 1);
	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";
	return 0;
}
