#include <iostream>
using namespace std;

int map[501][501] = {0};
int dp[501][501] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			cin >> map[i][j];
		}
	}
	dp[1][1] = map[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++){
			dp[i][j] = map[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, dp[n][i]);
	}
	cout << ans;

}
