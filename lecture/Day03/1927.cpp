#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

void push(int cmd){
	arr.push_back(cmd);
	int idx = arr.size() - 1;
	while (arr.size() > 1 && idx > 1 && arr[idx / 2] > arr[idx]) {
		int tmp = arr[idx];
		arr[idx] = arr[idx / 2];
		arr[idx / 2] = tmp;
		idx /= 2;
	}
}

void pop() {
	if (arr.size() <= 1) {
		cout << 0 << "\n";
		return ;
	}
	cout << arr[1] << "\n";
	arr[1] = arr[arr.size() - 1];
	arr.pop_back();
	int idx = 1;
	while (1)
	{
		int leftPos = idx * 2;
		int rightPos = idx * 2 + 1;
		if (leftPos > arr.size() - 1)
			break;
		int minPos = leftPos;
		if (rightPos <= arr.size() - 1 && arr[leftPos] > arr[rightPos])
			minPos = rightPos;
		if (arr[idx] > arr[minPos]) {
			int tmp = arr[idx];
			arr[idx] = arr[minPos];
			arr[minPos] = tmp;
			idx = minPos;
		} else
			break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	arr.push_back(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 0) {
			pop();
		} else if (cmd > 0) {
			push(cmd);
		}
	}
}
