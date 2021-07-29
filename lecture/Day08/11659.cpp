#include <iostream>
#include <vector>
using namespace std;

int arr[100001] = {0};
int dp[100001] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	dp[1] = arr[1];
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << '\n';
	}
}
