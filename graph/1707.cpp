#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[20001];
int check[20001] = {0};

bool dfs(int now, int group) {
	if (!check[now]) check[now] = group;
	for (int i = 0; i < graph[now].size(); i++){
		int next = graph[now].at(i);
		if (!check[next]) {
			if (!dfs(next, -group))
				return false;
		} else if (check[next] == group)
			return false;
	}
	return true;
}

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int v, e;
		cin >> v >> e;
		for (int j = 0; j <= v; j++){
			graph[j].clear();
			check[j] = 0;
		}
		for (int j = 0; j < e; j++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		bool ans = true;
		for (int j = 1; j <= v; j++) {
			if (check[j] == 0){
				if (!dfs(j, 1))
					ans = false;
			}
		}
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
