#include <iostream>
#include <vector>
using namespace std;

const int INF = 100000000;
int dist[501][501] = {0};

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}
	for(int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++){
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++){
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] != INF || dist[j][i] != INF) {
				cnt++;
			}
		}
		if (cnt == n - 1) sum++;
	}
	cout << sum;
}
