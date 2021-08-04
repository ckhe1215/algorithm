#include <iostream>
using namespace std;

long long arr[100001] = {0};
long long sum[100001] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	sum[1] = arr[1];
	for (int i = 2; i <= n; i++){
		sum[i] = max(sum[i - 1] + arr[i], arr[i]);
	}
	long long max = sum[1];
	for (int i = 2; i <= n; i++) {
		if (sum[i] > max)
			max = sum[i];
	}
	cout << max;
}
