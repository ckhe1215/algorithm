#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr[32001];
int edge[32001] = { 0 };
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		edge[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (edge[i] == 0)
			q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		int v = q.front();
		q.pop();
		cout << v << ' ';
		for (int j = 0; j < arr[v].size(); j++) {
			edge[arr[v][j]]--;
			if (edge[arr[v][j]] == 0)
				q.push(arr[v][j]);
		}
	}
}
