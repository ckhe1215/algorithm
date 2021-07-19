#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> tree[1000001];
int visited[1000001] = {0};
int en;
int sum;

int dfs(int r, int w) {
	visited[r] = 1;

	for (int i = 0; i < tree[r].size(); i++) {
		if (!visited[tree[r][i].first]){
			int tmp = dfs(tree[r][i].first, w + tree[r][i].second);
			if (sum < tmp) {
				sum = tmp;
				en = tree[r][i].first;
			}
		}
	}
	return w;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v;
	cin >> v;
	for (int i = 0; i < v; i++) {
		int n;
		cin >> n;
		while (1) {
			int a, b;
			cin >> a;
			if (a == -1) break;
			cin >> b;
			tree[n].push_back(make_pair(a, b));
		}
	}
	for(int i = 1; i <= v; i++) {
		if (!visited[i])
			dfs(i, 0);
	}
	for(int i = 0; i <= v; i++)
		visited[i] = 0;
	sum = 0;
	dfs(en, 0);
	cout << sum;
}
