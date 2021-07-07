#include <iostream>
using namespace std;
pair<int, int> arr[27];

void preOrder(int root) {
	int left = arr[root].first;
	int right = arr[root].second;
	cout << (char)(root + 'A');
	if (left > 0)
		preOrder(left);
	if (right > 0)
		preOrder(right);
}

void inOrder(int root){
	int left = arr[root].first;
	int right = arr[root].second;
	if (left > 0)
		inOrder(left);
	cout << (char)(root + 'A');
	if (right > 0)
		inOrder(right);
}

void postOrder(int root){
	int left = arr[root].first;
	int right = arr[root].second;
	if (left > 0)
		postOrder(left);
	if (right > 0)
		postOrder(right);
	cout <<(char)(root + 'A');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		arr[a - 'A'] = make_pair(b - 'A', c - 'A');
	}

	preOrder(0);
	cout << "\n";
	inOrder(0);
	cout << "\n";
	postOrder(0);
	cout << "\n";
	return 0;
}
