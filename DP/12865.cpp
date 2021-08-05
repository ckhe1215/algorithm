#include <iostream>
using namespace std;

int weight[101] = {0};
int value[101] = {0};
int dp[101][100001] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if(j < weight[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		}
	}
	cout << dp[n][k];
}
