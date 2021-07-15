#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001] = {0};
int visited[1001][1001] = {0};
int dx[] = {-1, 0, 0 , 1};
int dy[] = {0, -1, 1, 0};
queue<pair<int, int>> q;

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++){
			int a = x + dx[i];
			int b = y + dy[i];
			if (a >= 0 && b >= 0 && a < n && b < m && map[a][b] == 0 && visited[a][b] == 0) {
				visited[a][b] = visited[x][y] + 1;
				q.push(make_pair(a, b));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != -1 && visited[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < visited[i][j])
				max = visited[i][j];
		}
	}
	cout << max - 1;

	return 0;
}
