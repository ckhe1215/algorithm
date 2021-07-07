#include <iostream>
#include <queue>
using namespace std;

int map[101][101] = {0};
int visited[101][101] = {0};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n;

void dfs(int x, int y, int cnt) {
	if (visited[x][y]) return;
	visited[x][y] = 1;
	map[x][y] = cnt;
	for (int i = 0; i < 4; i++){
		int a = x + dx[i];
		int b = y + dy[i];
		if (a > 0 && b > 0 && a <= n && b <= n && visited[a][b] == 0 && map[a][b] == 1)
			dfs(a, b, cnt);
	}
}

int bfs(int cnt){
	queue<pair<int, int>> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == cnt){
				q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
		}
	}
	int result = 0;
	while (!q.empty()){
		int curSize = q.size();
		for(int j = 0; j < curSize; j++){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			int a, b;
			for (int i = 0; i < 4; i++) {
				a = x + dx[i];
				b = y + dy[i];
				if (a > 0 && b > 0 && a <= n && b <= n){
					if (map[a][b] && map[a][b] != cnt)
						return result;
					else if (!map[a][b]&& !visited[a][b]){
						visited[a][b] = 1;
						q.push(make_pair(a, b));
					}
				}
			}
		}
		result++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	}

	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1 && !visited[i][j])
				dfs(i, j, cnt++);
		}
	}

	int result = 10001;
	for (int i = 1; i < cnt; i++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				visited[a][b] = 0;
			}
		}
		result = min(result, bfs(i));
	}

	cout << result << "\n";

	return 0;
}
