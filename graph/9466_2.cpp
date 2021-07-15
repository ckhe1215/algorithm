#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
int visited[100001] = {0};
int cnt;

void dfs(int n, int start, int mem) {
	visited[n] = 1;
	for (int i = 0; i < graph[n].size(); i++) {
		if (visited[graph[n][i]] && graph[n][i] == start)
			cnt += mem;
		if (!visited[graph[n][i]]) {
			dfs(graph[n][i], start, mem + 1);
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cnt = 0;
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			visited[j] = 0;
			graph[j].clear();
			int num;
			cin >> num;
			graph[j].push_back(num);
		}
		for (int j = 1; j <=n; j++){
			if (!visited[j])
				dfs(j, j, 1);
		}
		cout << n - cnt << "\n";
	}
}
