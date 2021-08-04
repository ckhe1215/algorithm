#include <iostream>
using namespace std;

int arr[1001] = {0};
int lis[1001] = {0};
int lds[1001] = {0};
int res[1001] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	lis[1] = 1;
	for(int i = 2; i <= n; i++){
		int max = 0;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && lis[j] > max)
				max = lis[j];
		}
		lis[i] = max + 1;
	}
	lds[n] = 1;
	for(int i = n - 1; i >= 1; i--){
		int max = 0;
		for (int j = i; j <= n; j++) {
			if (arr[j] < arr[i] && lds[j] > max)
				max = lds[j];
		}
		lds[i] = max + 1;
	}
	int ret = 0;
	for(int i = 0; i <= n; i++){
		res[i] = lis[i] + lds[i] - 1;
		if (res[i] > ret)
			ret = res[i];
	}
	cout << ret;
}
