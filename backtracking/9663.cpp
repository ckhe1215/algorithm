#include <iostream>
using namespace std;

int n;
int cnt = 0;
int board[15] = {0};

int promising(int idx){
	for(int i = 0; i < idx; i++) {
		if (board[i] == board[idx] || abs(i - idx) == abs(board[i] - board[idx]))
			return 0;
	}
	return 1;
}

void n_queen(int idx) {
	if (idx == n) {
		cnt++;
		return;
	}
	for(int i = 0; i < n; i++){
		board[idx] = i;
		if (promising(idx) == 1){
			n_queen(idx + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	n_queen(0);
	cout << cnt;
}
