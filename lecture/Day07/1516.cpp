#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int b_time[501] = {0};
int indegree[501] = {0};
int ans[501] = {0};
vector<int> adj[501];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int sum = 0;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> b_time[i];
		while (1){
			int a;
			cin >> a;
			if (a == -1) break;
			adj[a].push_back(i);
			indegree[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}
	while(!q.empty()){
		int a = q.front();
		q.pop();
		ans[a] += b_time[a]; // 자기 자신 짓는 시간
		for (int j = 0; j < adj[a].size(); j++) {
			indegree[adj[a][j]]--;
			ans[adj[a][j]] = max(ans[adj[a][j]], ans[a]); // 선행 건물의 건설 시간 중 제일 큰 것
			if (indegree[adj[a][j]] == 0)
				q.push(adj[a][j]);
		}
	}
	for (int i = 1; i <= n; i++){
		cout << ans[i] << "\n";
	}
}
