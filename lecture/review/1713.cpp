#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pic {
	int num;
	int order;
	int cnt;
};
vector<pic> frame;
int arr[1001];

int compare(const pic &one, const pic &two) {
	if (one.cnt == two.cnt){
		return one.order < two.order;
	} else {
		return one.cnt < two.cnt;
	}
}

int compare2(const pic &one, const pic &two) {
	return one.num < two.num;
}

int main() {
	int n;
	int student;
	cin >> n;
	cin >> student;
	for (int i = 0; i < student; i++){
		cin >> arr[i];
	}
	for (int i = 0; i < student; i++) {
		int already = 0;
		for(int j = 0; j < frame.size(); j++) {
			if (frame[j].num == arr[i]) {
				frame[j].cnt++;
				already = 1;
				break;
			}
		}
		if (!already){
			pic tmp = {arr[i], i, 1};
			if (frame.size() < n){
				frame.push_back(tmp);
			} else {
				sort(frame.begin(), frame.end(), compare);
				frame[0] = tmp;
			}
		}
	}
	sort(frame.begin(), frame.end(), compare2);
	for (int i = 0; i < frame.size(); i++) {
		cout << frame[i].num << " ";
	}
}
