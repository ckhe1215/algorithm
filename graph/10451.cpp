#include <iostream>
using namespace std;

int arr[1001] = {0};
int visited[1001] = {0};

void dfs(int start, int n){
	if (visited[start]) return;
	visited[start] = 1;
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && i == arr[start])
			dfs(i, n);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		int cnt = 0;
		int n;
		cin >> n;
		for(int a = 0; a <= 1000; a++) {
			arr[a] = 0;
			visited[a] = 0;
		}
		for (int j = 0; j < n; j++) {
			cin >> arr[j + 1];
		}
		for (int k = 1; k <= n; k++) {
			if (visited[k]) continue;
			cnt++;
			dfs(k, n);
		}
		cout << cnt << '\n';
	}
	return 0;
}
