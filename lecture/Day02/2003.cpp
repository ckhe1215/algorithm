#include <iostream>
using namespace std;

int arr[10001] = {0};
int arr_sum(int start, int end) {
	int sum = 0;
	for (int i = start; i <= end; i++)
		sum += arr[i];
	return sum;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int left = 0;
	int right = 0;
	while (left < n && right < n)
	{
		if (arr_sum(left, right) == m) {
			cnt++;
			left++;
		} else if (arr_sum(left, right) < m) {
			right++;
		} else
			left++;
	}
	cout << cnt;
}
