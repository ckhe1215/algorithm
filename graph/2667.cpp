#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[26][26] = {0};
int visited[26][26] = {0};
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
vector<int> list;

void dfs(int i, int j, int cnt) {
	if (visited[i][j]) return;
	visited[i][j] = 1;
	for(int k = 0; k < 4; k++) {
		int a = i + dx[k];
		int b = j + dy[k];
		if (map[a][b] == 1 && visited[a][b] == 0){
			dfs(a, b, cnt);
			list[cnt]++;
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++){
			map[i][j + 1] = str[j] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				list.push_back(1);
				dfs(i, j, cnt);
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	sort(list.begin(), list.end());
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << "\n";
	}
	return 0;
}
