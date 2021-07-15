#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[20001];
int visited[20001] = {0};
int fail = 0;

void dfs(int s, int flag) {
	if(visited[s]) return;
	visited[s] = flag;
	for (int i = 0; i < graph[s].size(); i++) {
		if (visited[graph[s][i]] == flag){
			fail = 1;
			return ;
		}
		if (!visited[graph[s][i]])
			dfs(graph[s][i], -flag);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		fail = 0;
		int v, e;
		cin >> v >> e;
		for (int j = 0; j <= v; j++){
			graph[j].clear();
			visited[j] = 0;
		}
		for (int j = 0;  j < e; j++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for (int j = 1; j <= v; j++){
			if (!visited[j])
				dfs(j, 1);
		}
		if (fail == 1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
