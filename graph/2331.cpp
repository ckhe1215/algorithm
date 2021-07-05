#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, p;
	int loc = -1;
	vector<int> v;
	cin >> a >> p;
	v.push_back(a);
	while (1) {
		int num = 0;
		while (a) {
			int temp = a % 10;
			for (int i = 1; i < p; i++)
				temp *= a % 10;
			num += temp;
			a /= 10;
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == num)
				loc = i;
		}
		if (loc > -1) break;
		v.push_back(num);
		a = num;
	}
	cout << loc;
	return 0;
}
