#include <iostream>
using namespace std;

int arr[1025][1025] = {0};
int dp[1025][1025] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		dp[i][1] = arr[i][1];
		for(int j = 1; j <= n; j++){
			dp[i][j] = dp[i][j - 1] + arr[i][j];
		}
	}
	for(int i = 1; i <= m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int sum = 0;
		for(int a = x1; a <= x2; a++){
			sum += (dp[a][y2] - dp[a][y1 - 1]);
		}
		cout << sum << '\n';
	}
}
