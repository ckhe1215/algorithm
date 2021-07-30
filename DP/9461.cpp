#include <iostream>
using namespace std;

long long dp[101] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt;
	cin >> cnt;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	for (int i = 5; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	for(int i = 0; i < cnt; i++) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}
