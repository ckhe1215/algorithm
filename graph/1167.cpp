#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> tree[100001];
int visited[100001] = {0};
int ans = 0;
int ed; // 마지막 노드

void dfs(int start, int distance) {
	visited[start] = 1;

	if (distance > ans)
	{
		ans = distance;
		ed = start;
	}

	for (int i = 0; i < tree[start].size(); i++) {
		int p = tree[start][i].first;
		int d = tree[start][i].second;
		if (!visited[p]){
			dfs(p, distance + d);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v;
	cin >> v;
	for (int i = 1; i <= v; i++) {
		int a;
		cin >> a;
		while (1) {
			int b, c;
			cin >> b;
			if (b == -1)
				break;
			cin >> c;
			tree[a].push_back(make_pair(b, c)); // b는 점, c는 거리
		}
	}

	dfs(1, 0);
	ans = 0;
	for (int i = 0; i <= v; i++)
		visited[i] = 0;
	dfs(ed, 0);

	cout << ans;

	return 0;
}
