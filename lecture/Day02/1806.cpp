#include <iostream>
#include <vector>
using namespace std;

vector<long long> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		arr.push_back(num);
	}
	arr.push_back(0);
	int left = 0;
	int right = 0;
	int length = n + 1;
	long long sum = arr[0];
	while (1) {
		if (sum < m) {
			sum += arr[++right];
		}
		else {
			if (abs(right - left) + 1 < length)
				length = abs(right - left) + 1;
			sum -= arr[left++];
		}
		if (right >= n)
			break;
	}
	if (length == n + 1)
		cout << 0;
	else
		cout << length;
}
