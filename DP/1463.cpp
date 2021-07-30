#include <iostream>
using namespace std;

int dp[1000001] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= n; i++){
		int a = -1;
		int b = -1;
		int c = -1;
		if (i % 2 == 0)
			a = i / 2;
		if (i % 3 == 0)
			b = i / 3;
		c = i - 1;
		if (a == -1)
			a = 2147483647;
		else
			a = dp[a];
		if (b == -1)
			b = 2147483647;
		else
			b = dp[b];
		int min_num = min(min(a, b), dp[c]);
		dp[i] = min_num + 1;
	}
	cout << dp[n];
}
