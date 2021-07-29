#include <iostream>
using namespace std;

int arr[301] = {0};
int dp[301] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	dp[1] = arr[1];
	for(int i = 2; i <= n; i++){
		dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
	}
	cout << dp[n];
}
