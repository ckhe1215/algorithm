#include <iostream>
using namespace std;

int n, m;
int arr[9] = {0};
int visited[9] = {0};

void recursive(int s, int cnt) {
	if (cnt == m) {
		for(int i = 0; i < m; i++){
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return ;
	}
	for (int i = s; i <= n; i++) {
		visited[i]++;
		arr[cnt] = i;
		recursive(i, cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	recursive(1, 0);
}
