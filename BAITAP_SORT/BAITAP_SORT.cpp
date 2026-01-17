#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#define pb push_back

void Bai1() {
	vector<string> str = { "eat", "tea", "tan", "ate", "nat", "bat" }, str_tmp = str;
	map<string, vector<string>> m;
	for (int i = 0; i < str.size(); i++) {
		sort(str_tmp[i].begin(), str_tmp[i].end());
		m[str_tmp[i]].pb(str[i]);
	}
	for (auto item : m) {
		for (auto item1 : item.second) cout << item1 << ' ';
		cout << '\n';
	}
}

void Bai2() {
	vector<int> v = { 3, 30, 34, 5, 9 };
	vector<string> str;
	for (int i = 0; i < v.size(); i++) {
		string tmp = to_string(v[i]);
		str.pb(tmp);
	}
	sort(str.begin(), str.end(), [](string a, string b) {
		return a + b > b + a;
		});
	for (auto item : str) cout << item;
}

int main()
{
	
	return 0;
}