#include <iostream>

using namespace std;

char tree[26][3] = {0};

void preOrder(int root) {
	cout << (char)(root + 'A');
	if (tree[root][0] >= 'A' && tree[root][0] <= 'Z')
		preOrder(tree[root][0] - 'A');
	if (tree[root][1] >= 'A' && tree[root][1] <= 'Z')
		preOrder(tree[root][1] - 'A');
}

void midOrder(int root) {
	if (tree[root][0] >= 'A' && tree[root][0] <= 'Z')
		midOrder(tree[root][0] - 'A');
	cout << (char)(root + 'A');
	if (tree[root][1] >= 'A' && tree[root][1] <= 'Z')
		midOrder(tree[root][1] - 'A');
}

void postOrder(int root) {
	if (tree[root][0] >= 'A' && tree[root][0] <= 'Z')
		postOrder(tree[root][0] - 'A');
	if (tree[root][1] >= 'A' && tree[root][1] <= 'Z')
		postOrder(tree[root][1] - 'A');
	cout << (char)(root + 'A');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char node, left, right;
		cin >> node >> left >> right;
		tree[node - 'A'][0] = left;
		tree[node - 'A'][1] = right;
	}
	preOrder(0);
	cout << "\n";
	midOrder(0);
	cout << "\n";
	postOrder(0);
	cout << "\n";
}
