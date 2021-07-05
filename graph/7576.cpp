#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001] = {0};
int visited[1001][1001] = {0};
queue<pair<int, int>> q;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) {
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			if (a < 1 || b < 1 || a > n || b > m) continue;
			if (map[a][b] == 0) {
				map[a][b] = 1;
				visited[a][b] = visited[x][y] + 1;
				q.push(make_pair(a, b));
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) {
			if (map[i][j] == 0){
				cout << -1;
				return 0;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) {
			if (visited[i][j] > cnt)
				cnt = visited[i][j];
		}
	}

	cout << cnt;
	return 0;
}
