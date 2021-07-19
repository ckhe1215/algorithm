#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pic{
	int student;
	int order;
	int count;
};

bool compare(const pic &one, const pic &two) {
	if (one.count < two.count) {
		return true;
	} else if (one.count == two.count) {
		return one.order < two.order;
	} else
		return false;
}

bool compare2(const pic &one, const pic &two) {
	if (one.student < two.student) {
		return true;
	} else
		return false;
}

int isAlready(int num, vector<pic>frames) {
	int res = -1;
	for (int i = 0; i < frames.size(); i++) {
		if (frames[i].student == num){
			res = i;
			break;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> list;
	int n;
	cin >> n;
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int num;
		cin >> num;
		list.push_back(num);
	}
	vector<pic> frames;
	for (int i = 0; i < cnt; i++) {
		int loc = isAlready(list[i], frames);
		if (loc > -1) {
			frames[loc].count++;
		} else if (frames.size() < n) {
			pic temp = {list[i], i, 1};
			frames.push_back(temp);
		} else {
			sort(frames.begin(), frames.end(), compare);
			frames.erase(frames.begin());
			pic temp = {list[i], i, 1};
			frames.push_back(temp);
		}
	}
	sort(frames.begin(), frames.end(), compare2);
	for (int i = 0; i < frames.size(); i++) {
		cout << frames[i].student << " ";
	}
}
