#include <iostream>
using namespace std;

int arr[1001] = {0};
int dp[1001] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	dp[1] = 1;
	for(int i = 2; i <= n; i++) {
		int max = 0;
		for(int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && dp[j] > max)
				max = dp[j];
		}
		dp[i] = max + 1;
	}
	int res = 1;
	for (int i = 1; i <= n; i++){
		if (dp[i] > res)
			res = dp[i];
	}
	cout << res;
}
