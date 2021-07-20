#include <iostream>
using namespace std;

char map[51][51] = {0};
int visited[51][51] = {0};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, m;

void dfs(int x, int y) {
	visited[x][y] = 1;
	for(int i = 0; i < 4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (new_y < 0 || new_x < 0 || new_x >= n || new_y >= m || map[new_x][new_y] == 'H') {

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for(int j = 0; j < m; j++) {
			map[i][j] = str[j];
		}
	}

	dfs(0, 0);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}
