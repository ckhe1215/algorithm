#include <iostream>
#include <queue>
using namespace std;

struct point {
	int x;
	int y;
	char type;
};

char map[51][51] = {0};
int visited[51][51] = {0};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
queue<point> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++){
			map[i][j] = s[j];
		}
	}
	point s;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == '*') {
				point w = {i, j, '*'};
				q.push(w);
				visited[i][j] = 1;
			}
			if (map[i][j] == 'S') {
				s = {i, j, 'S'};
				visited[i][j] = 1;
			}
		}
	}
	q.push(s);
	while (!q.empty()) {
		point now = q.front();
		q.pop();
		int x = now.x;
		int y = now.y;
		char t = now.type;
		for (int i = 0; i < 4; i++){
			int a = x + dx[i];
			int b = y + dy[i];
			if (a < 0 || b < 0 || a >= r || b >= c) continue;
			if (t == '*' && (map[a][b] == '.' || map[a][b] == 'S') && !visited[a][b]) {
				point tmp = {a, b, '*'};
				q.push(tmp);
				visited[a][b] = visited[x][y] + 1;
				map[a][b] = '*';
			} else if (t == 'S' && (map[a][b] == '.' || map[a][b] == 'D') && !visited[a][b]) {
				point tmp = {a, b, 'S'};
				q.push(tmp);
				visited[a][b] = visited[x][y] + 1;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'D' && visited[i][j] > 0) {
				cout << visited[i][j] - 1;
				return 0;
			}
		}
	}
	cout << "KAKTUS";
	return 0;
}
