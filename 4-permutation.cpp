#include <iostream>
#include <set>
using namespace std;
set<string> s;
void getPerm(string str, int i) {
	if (i == str.size() && s.find(str) == s.end()) {
		s.insert(str);
		cout << str << endl;
		return;
	}
	for (int j = i; j < str.size(); j++) {
		swap(str[i], str[j]);
		getPerm(str, i + 1);
	}
}
void perm(string str, int i, int flag, string val) {
	if (flag) {
		val += str[i];
	}
	if (i == str.size() - 1) {
		if (val.size()) {
			getPerm(val, 0);
		}
		return;
	}
	perm(str, i + 1, 0, val);
	perm(str, i + 1, 1, val);
}
int main() {
	string str;
	cin >> str;
	string val = "";
	perm(str, 0, 0, val);
	perm(str, 0, 1, val);
}