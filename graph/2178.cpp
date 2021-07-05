#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int map[101][101] = {0};
	int visited[101][101] = {0};
	int dx[] = {-1, 0, 0, 1};
	int dy[] = {0, -1, 1, 0};
	queue<pair<int, int>> q;
	string str;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j] = str[j] - '0';
		}
	}

	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			if (a < 0 || b < 0 || a >= n || b >= m) continue;
			if (map[a][b] == 1 && visited[a][b] == 0){
				visited[a][b] = visited[x][y] + 1;
				q.push(make_pair(a, b));
			}
		}
	}

	cout << visited[n - 1][m - 1];
}
