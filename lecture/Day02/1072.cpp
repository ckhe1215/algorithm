#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long x, y;
	cin >> x >> y;
	long long z = 100 * y / x;
	if (z >= 99)
		cout << -1;
	else {
		int end = x;
		int start = 0;
		while (start < end) {
			int mid = (end + start) / 2;
			long long new_rate = (100 * (mid + y) / (x + mid));
			if (new_rate == z) {
				start = mid + 1;
			} else {
				end = mid;
			}
		}
		cout << end;
	}

}
