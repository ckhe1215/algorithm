#include <iostream>
#include <vector>
using namespace std;

struct bus{
	int start;
	int end;
	int cost;
};
int dist[101][101];
vector<bus>list;

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < 101; i++){
		for (int j = 0; j < 101; j++) {
			dist[i][j] = 1000000000;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c < dist[a][b])
			dist[a][b] = c;
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == 1000000000 || i == j)
				cout << "0 ";
			else
				cout << dist[i][j] << ' ';
		}
		cout << "\n";
	}
}
