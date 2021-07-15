#include <iostream>
using namespace std;

int graph[50][50] = {0};
int visited[50][50] = {0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int w, h;

int cnt = 0;

void dfs(int i, int j) {
	if (visited[i][j]) return;
	visited[i][j] = 1;
	for(int a = 0; a < 8; a++){
		int x = i + dx[a];
		int y = j + dy[a];
		if (x >= 0 && x < h && y >= 0 && y < w) {
			if (!visited[x][y] && graph[x][y])
				dfs(x, y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> w >> h;
		if (!w && !h)
			break;
		cnt = 0;
		for(int i = 0; i < h; i++){
			for (int j = 0; j < w; j++) {
				cin >> graph[i][j];
				visited[i][j] = 0;
			}
		}
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++) {
				if (!visited[i][j] && graph[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
