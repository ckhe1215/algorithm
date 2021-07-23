#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree;

long long cut(int mid) {
	long long sum = 0;
	for (int i = 0; i < tree.size(); i++) {
		if (tree[i] > mid)
			sum += tree[i] - mid;
	}
	return sum;
}

// 파라메트릭 서치
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	long long min = 0;
	long long max = 0;
	for (int i = 0; i < n; i++) {
		long long h;
		cin >> h;
		tree.push_back(h);
		if (h > max)
			max = h;
	}
	long long result;
	while (1) {
		long long mid = (min + max) / 2;
		long long sum = cut(mid);
		if (sum == m) {
			result = mid;
			break;
		}
		else if (sum < m) {
			// 나무를 더 잘라야함(mid를 낮춰야함)
			max = mid - 1;
		} else {
			// 나무를 덜 잘라도 되는지 알아보자
			min = mid + 1;
			result = mid;
		}
		if (min > max)
			break;
	}
	cout << result;
}
