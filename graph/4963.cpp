#include <iostream>

using namespace std;

int graph[51][51] = {0};
int visited[51][51] = {0};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int a, int b, int h, int w) {
	if (visited[a][b] == 1) return;
	visited[a][b] = 1;
	for(int i = 0; i < 8; i++) {
		int x = a + dx[i];
		int y = b + dy[i];
		if (graph[x][y] == 1 && visited[x][y] == 0)
			dfs(x, y, h, w);
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		int cnt = 0;
		for(int i = 0; i < 51; i++){
			for (int j = 1; j < 51; j++) {
				graph[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				int a;
				cin >> a;
				if (a == 1)
					graph[i][j] = 1;
			}
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (visited[i][j] == 0 && graph[i][j] == 1) {
					dfs(i, j, h, w);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
