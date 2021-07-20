#include <iostream>
#include <queue>
using namespace std;

struct point{
	int x;
	int y;
	char type;
};

char map[51][51] = {0};
int visited[51][51] = {0};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int findAns = 0;
int ans;
queue<point> q;

int main() {
	int r, c;
	cin >> r >> c;
	point w, g;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			map[i][j] = str[j];
			if (map[i][j] == '*') {
				w = {i, j, '*'};
				q.push(w);
				visited[i][j] = 1;
			} else if (map[i][j] == 'S') {
				g = {i, j , 'S'};
				visited[i][j] = 1;
			}
		}
	}
	q.push(g);

	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		char t = q.front().type;
		q.pop();
		if (t == 'S' && map[x][y] == 'D') {
			findAns = 1;
			ans = visited[x][y] - 1;
			break;
		}
		for(int i = 0; i < 4; i++){
			int a = x + dx[i];
			int b = y + dy[i];
			if (a < 0 || b < 0 || a >= r || b >= c) continue;
			if (t == '*' && (map[a][b] == '.' || map[a][b] == 'S') && !visited[a][b]) {
				point tmp = {a, b, '*'};
				q.push(tmp);
				map[a][b] = '*';
				visited[a][b] = visited[x][y] + 1;
			} else if(t == 'S' && (map[a][b] == '.' || map[a][b] == 'D' ) && !visited[a][b]) {
				point tmp = {a, b, 'S'};
				q.push(tmp);
				visited[a][b] = visited[x][y] + 1;
			}
		}
	}

	if (!findAns)
		cout << "KAKTUS";
	else
		cout << ans;

	return 0;

}
