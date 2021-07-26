#include <iostream>
using namespace std;

int n, m;
int visited[9] = {0};

void recursive(int s, int cnt){
	if (cnt == m){
		for (int i = 1; i <= n; i++) {
			if (visited[i])
				cout << i << " ";
		}
		cout << "\n";
		return ;
	}
	for (int i = s; i <= n; i++){
		if (!visited[i]){
			visited[i] = 1;
			recursive(i, cnt + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	recursive(1, 0);
}
