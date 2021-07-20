#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
10^9 범위 벗어나는 게 문제일거라고 생각했는데
알고보니 mod에서 음수 처리를 잘못하고 있었다.
덕분에 쓸데없는 시도만 여러 번 했네...^^
문제에서 말한 div/mod 음수 처리조건을 따로 처리해줄 필요가 없다고 한다.
*/

int calc(int num, vector<pair<string, int>> stmt) {
	stack<long long> go;
	go.push(num);
	for (int i = 0; i < stmt.size(); i++) {
		string str = stmt.at(i).first;
		long long n = stmt.at(i).second;
		if (str == "NUM")
			go.push(n);
		else if (str == "POP"){
			if (go.size() < 1) return -1;
			go.pop();
		}
		else if (str == "INV") {
			if (go.size() < 1) return -1;
			int tmp = go.top();
			go.pop();
			go.push(-tmp);
		}
		else if (str == "DUP"){
			if (go.size() < 1) return -1;
			go.push(go.top());
		}
		else if (str == "SWP") {
			if (go.size() < 2) return -1;
			int one = go.top();
			go.pop();
			int two = go.top();
			go.pop();
			go.push(one);
			go.push(two);
		}
		else if (str == "ADD"){
			if (go.size() < 2) return -1;
			long long one = go.top();
			go.pop();
			long long two = go.top();
			go.pop();
			long long tmp = one + two;
			if (tmp > 1000000000 || tmp < -1000000000) return -1;
			go.push(tmp);
		}
		else if (str == "SUB") {
			if (go.size() < 2) return -1;
			long long one = go.top();
			go.pop();
			long long two = go.top();
			go.pop();
			long long tmp = two - one;
			if (tmp > 1000000000 || tmp < -1000000000) return -1;
			go.push(tmp);
		}
		else if (str == "MUL") {
			if (go.size() < 2) return -1;
			long long one = go.top();
			go.pop();
			long long two = go.top();
			go.pop();
			long long tmp = one * two;
			if (tmp > 1000000000 || tmp < -1000000000) return -1;
			go.push(tmp);
		}
		else if (str == "DIV") {
			if (go.size() < 2) return -1;
			int one = go.top();
			go.pop();
			int two = go.top();
			go.pop();
			if (one == 0) return -1;
			int ans = two / one;
			go.push(ans);
		}
		else if (str == "MOD") {
			if (go.size() < 2) return -1;
			int one = go.top();
			go.pop();
			int two = go.top();
			go.pop();
			if (one == 0) return -1;
			int ans = two % one;
			go.push(ans);
		}
	}
	if (go.size() == 1)
		cout << go.top() << "\n";
	else
		return -1;
	return 0;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		vector<pair<string, int>> stmt;
		while(1)
		{
			string str;
			cin >> str;
			if (str == "END") break;
			if (str == "QUIT") return 0;
			int param = 0;
			if (str == "NUM")
				cin >> param;
			stmt.push_back(make_pair(str, param));
		}
		int cnt;
		cin >> cnt;
		for(int i = 0;  i < cnt; i++) {
			int num;
			cin >> num;
			if (calc(num, stmt) == -1)
				cout << "ERROR\n";
		}
		cout << "\n";
	}
	return 0;
}
