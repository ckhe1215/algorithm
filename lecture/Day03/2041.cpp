#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<long long> tree;
int n, m, k, s;

void init() {
	for (int i = 0; i < s; i++){
		tree.push_back(0);
	}
	for (int i = 0; i < arr.size(); i++) {
		tree.push_back(arr[i]);
	}
	while(tree.size() < s * 2) {
		tree.push_back(0);
	}
	for(int i = s - 1; i > 0; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

long long query(int node, int left, int right, int queryLeft, int queryRight) {
	if (queryRight < left || right < queryLeft)
		return 0;
	else if (queryLeft <= left && right <= queryRight) {
		return tree[node];
	} else {
		int mid = (left + right) / 2;
		long long leftResult = query(node * 2, left, mid, queryLeft, queryRight);
		long long rightResult = query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
		return leftResult + rightResult;
	}
}

void update(int target, long long value) {
	int node = s + target - 1;
	tree[node] = value;
	node /= 2;
	while (node){
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		node /= 2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	s = 1; // s는 첫번째 리프노드의 번호
	while (s < n) {
		s *= 2;
	}
	init();
	for(int i = 0; i < m + k; i++){
		int a;
		cin >> a;
		if (a == 1) {
			int b;
			long long c;
			cin >> b >> c;
			update(b, c);
		} else if (a == 2) {
			int b, c;
			cin >> b >> c;
			if (c < b){
				int temp = b;
				b = c;
				c = temp;
			}
			cout << query(1, 1, s, b, c) << "\n";
		}
	}
}

/*
S = 1;
while (S < N) {
	S *= 2;
}
tree = new long [S * 2];

void initBU() {
	//leaf에 값 반영
	for (int i = 0; i < N; i++) {
		tree[S + i] = nums[i];
	}
	// 내부노드 채움
	for (int i = S - 1; i > 0; i--) {
		tree[i] = tree[i * 2] +  tree[i * 2 + 1];
	}
}

long query(int left, int right, int node, int queryLeft, int queryRight) {
	// 연관이 없음-> 결과에 영향이 없는 값 리턴
	if (queryRight < left || right < queryLeft) {
		return 0;
	}
	// 판단 가능 -> 현재 노드 값 리턴
	else if (queryLeft <= left && right <= queryRight) {
		return tree[node];
	}
	// 판단 불가, 자식에게 위임, 자식에서 올라온 합을 리턴
	else {
		int mid = (left + right) / 2;
		long leftResult = query(left, mid, node * 2, queryLeft, queryRight);
		long rightResult = query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
		return leftResult + rightResult;
	}
}

void update (int left, int right, int node, int target) {
	// 연관없음
	if (target < left || right < target ) {
		return ;
	}
	// 연관 있음 -> 현재 노드에 diff 반영 -> 자신에게 diff 전달
	else {
		tree[node] += diff;
		if (left != right) {
			int mid = (left + right) / 2;
			update(left, mid, node * 2, target, diff);
			update(mid + 1, right, node * 2 + 1, target, diff);
		}
	}
}

long queryBU(int queryLeft, int queryRight) {
	// Leaf에서 left right 설정
	int left = S + queryLeft - 1;
	int right = S + queryRight - 1;
	long sum = 0;
	while (left <= right) {
		// 좌측 노드가 홀수이면 현재 노드값 사용하고 한 칸 옆으로
		if (left % 2 == 1)
			sum += tree[left++];
		// 우측 노드가  짝수이면 현재 노드 값 사용하고 한칸 옆으로
		if (right % 2 == 0) {
			sum += tree[right--];
		}
		// 좌측, 우측 모두 부모로 이동
		left /= 2;
		right /= 2;
	}
	return sum;
}

void updateBu(int target, long value) {
	// leaf에서 타겟을 찾음
	int node = S + target - 1;
	// value 반영
	tree[node] = value;
	//루트에 도달할때까지 부모에 값 반영
	node /= 2;
	while (node > 0) {
		 tree[node] = tree[node * 2] + tree[node * 2 + 1];
		 node /= 2;
	}
}
*/
