#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define pb push_back

void strCount(vector<string> q, vector<int>& qc) {
	for (int i = 0; i < q.size(); i++) {
		map<char, int> m;
		string str = q[i];
		for (int j = 0; j < str.size(); j++) 
			m[str[j]]++;
		int res = (*m.begin()).second;
		qc.pb(res);
	}
}

void bai2() {
	vector<string> q, w;
	vector<int> qc, wc;
	strCount(q, qc);
	strCount(w, wc);
	sort(wc.begin(), wc.end());
	int Size = q.size();
	for (int i = 0; i < Size; i++) {
		auto it = upper_bound(wc.begin(), wc.end(), qc[i]);
		int index = it - wc.begin();
		cout << wc.size() - index << ' ';
	}
}

int main()
{
	int k = 7;
	vector<int> a = { 2,3,1,2,4,3 };
	vector<int> sum;
	int tmp = 0;
	for (int i = 0; i < a.size(); i++) {
		tmp += a[i];
		sum.pb(tmp);
	}
	int l = 0, r = a.size() - 1;
	int res = INT_MAX;
	while (l <= r) {
		int m = (l + r) / 2;
		if (l == 0)
			int suml = sum[m];
		
		  
	}
	return 0;
}