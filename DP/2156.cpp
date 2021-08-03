#include <iostream>
using namespace std;

int arr[10001] = {0};
int dp[10001] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(arr[i] + dp[i - 2], dp[i - 1]), arr[i] + arr[i - 1] + dp[i - 3]);
	}
	cout << dp[n];
}
