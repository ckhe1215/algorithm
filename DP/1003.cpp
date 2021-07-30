#include <iostream>
#include <vector>
using namespace std;

vector<int> num;
int max_num = 0;
int fib_0[41] = {0};
int fib_1[41] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int n;
		cin >> n;
		num.push_back(n);
		max_num = max(n, max_num);
	}
	fib_0[0] = 1;
	fib_0[1] = 0;
	fib_1[0] = 0;
	fib_1[1] = 1;
	for (int i = 2; i <= max_num; i++){
		fib_0[i] = fib_0[i - 1] + fib_0[i - 2];
		fib_1[i] = fib_1[i - 1] + fib_1[i - 2];
	}
	for (int i = 0; i < num.size(); i++){
		cout << fib_0[num[i]] << ' ' << fib_1[num[i]] << '\n';
	}
}
