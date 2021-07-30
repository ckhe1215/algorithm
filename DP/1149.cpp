#include <iostream>
using namespace std;

int map[1001][4] = {0};
int dp[1001][4] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt;
	cin >> cnt;
	for(int i = 1; i <= cnt; i++){
		for (int j = 1; j <= 3; j++) {
			cin >> map[i][j];
		}
	}
	dp[1][1] = map[1][1];
	dp[1][2] = map[1][2];
	dp[1][3] = map[1][3];
	for (int i = 1; i < cnt; i++){
		dp[i + 1][1] = min(dp[i][2], dp[i][3]) + map[i + 1][1];
		dp[i + 1][2] = min(dp[i][1], dp[i][3]) + map[i + 1][2];
		dp[i + 1][3] = min(dp[i][1], dp[i][2]) + map[i + 1][3];
	}
	int res= min(min(dp[cnt][1], dp[cnt][2]), dp[cnt][3]);
	cout << res;
}
