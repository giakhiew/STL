#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cctype>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <string>
using namespace std;

void BubbleSort(vector<int>& v) {
	bool swapped = false;
	do {
		swapped = false;
		for (int i = 1; i < v.size(); i++) {
			if (v[i] < v[i - 1]) {
				swap(v[i], v[i - 1]);
				swapped = true;
			}
		}
	} while (swapped == true);
}

void SelectionSort(vector<int>& v) {
	size_t Size = v.size() - 1;
	for (int i = 0; i < Size; i++) {
		int min = INT_MAX;
		for (int j = 0; j < Size; j++) {
			if (min > v[j]) {
				min = j;
			}
		}
		swap(v[i], v[min]);
	}
}

//for (int j = i - 1; j >= 0; --j) {
//	if (key < v[j]) {
//		v[j + 1] = v[j];
//		if (j == 0) v[j] = key;
//	}
//	else {
//		v[j + 1] = key;
//		break;
//	}
//
//}

void InsertionSort(vector<int>& v) {
	for (int i = 1; i < v.size(); i++) {
		int key = v[i];
		int j = i - 1;
		while (j >= 0 && key < v[j]) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = key;
	}
}

void CountingSort(vector<int>& arr) {
	/*map<int, int> m;
	for (auto item : arr) {
		m[item]++;
	}

	int i = 0;

	for (auto item : m) {
		if (item.second > 0) {
			arr[i] = item.first;
			i++;
			item.second--;
		}
	}*/

	//MAX
	int max = INT_MIN;
	for (auto item : arr) {
		if (item > max) max = item;
	}

	vector<int> arr2(max + 1);

	for (int i = 0; i < arr.size(); i++) {
		arr2[arr[i]]++;
	}

	int j = 0;

	vector<int> output(arr.size());
	for (int i = 0; i <= max; i++) {
		if (arr2[i] > 0) {
			arr[j] = i;
			j++;
			arr2[i]--;
			--i;
		}
	}
}

void ThuatToanDoiCho(int n,vector<int>& arr) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) swap(arr[i], arr[j]);
		}
		cout << "Buoc " <<i+1 <<": ";
		for (auto item : arr) cout << item << " ";
		cout << endl;
	}
}

void ThuatToanSapXepChon(int n, vector<int>& arr) {
	int k;
	for (int i = 0; i < n - 1; i++) {
		int min = INT_MAX;
		k = i;
		for (int j = i; j < n; j++) {
			if (arr[j] < min) {
				min = arr[j];
				k = j;
			}
		}

		swap(arr[i],arr[k]);

		cout << "Buoc " << i + 1 << ": ";
		for (auto item : arr) cout << item << " ";
		cout << endl;
	}
}
//5 7 3 2
void ThuatToanSapXepChen(int n, vector<int>& arr) {
	int key;
	int tam;
	for (int i = 1; i < n; i++) {
		key = arr[i];
		tam = i;
		for (int j = i-1; j >= 0; j--) {
			if (arr[j] > key) {
				arr[j+1] = arr[j];
				tam = j;
			}
		}
		arr[tam] = key;
	}
}

void ThuatToanSapXepNoiBot(int n, vector<int>& arr) {
	int i = 0;
	bool swapped = true;
	while (swapped == true) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		if (swapped == true) {
			cout << "Buoc " << i + 1 << ": ";
			for (auto item : arr) cout << item << " ";
			cout << endl;
		}	
		i++;
	}
}

void SoCapKhieuVu(int nam, int nu, vector<int> arrnam, vector<int> arrnu) {
	int j = 0;
	sort(arrnam.begin(), arrnam.end());
	sort(arrnu.begin(), arrnu.end());

	for (int i = 0; i < arrnam.size(); i++) {
		if (arrnu[j] < arrnam[i]) j++;
	}
	cout << j;
}

void NhaGanNhat(int n, vector<int> arr) {
	sort(arr.begin(), arr.end());

	int min = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			int hieu = abs(arr[j] - arr[j + 1]);
			if (hieu < min) min = hieu;
		}
	}
	cout << min;
}

void VienGachCaoNhat(int n, vector<int> arr) {
	sort(arr.begin(), arr.end(),greater<int>());
	
	int DoCung = arr[0];
	int length = 1;
	for (int i = 1; i < n; i++) {
		if (DoCung == 0) break;
		else {
			DoCung = min(DoCung - 1, arr[i]);
			length++;
		}
	}
	cout << length;
}

void VatSuaBo(int n, vector<int> arr) {
	sort(arr.begin(), arr.end(), greater<int>());
	int sum = 0;
	int tam = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] - tam <= 0) break;
		sum += arr[i] - tam;
		tam++;
	}
	cout << sum;
}

void DoiCho(int n, vector<int> arr) {
	sort(arr.begin(), arr.end());
	int Size = n / 2;
	int j = n - 1;
	for (int i = 0; i < Size; i++) {
		cout << arr[i] << arr[j] << endl;
		j--;
	}
}
//5 8 2 7 8 3
void SapXepChen(int n, vector<int> arr) {
	int key, tam;
	for (int i = 1; i < n; i++) {
		tam = i;
		key = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			if (key < arr[j]) {
				arr[j + 1] = arr[j];
				tam = j;
			}
		}
		arr[tam] = key;
		cout << key << " " << tam<<endl;
	}
}

void ProblemsA(int n, int k, vector<int> arr) {
	sort(arr.begin(), arr.end());
	int sum = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] - arr[i - 1] <= k) continue;
		else sum++;
	}
	cout << sum;
}
//vector<vector<int>>

int TimKiemNhiPhan(vector<int> arr, int l, int r, int x) {
	/*int m = (l + r) * 1.0 / 2;
	while (l < r) {
		if (x == arr[m]) break;
		if (x < arr[m]) m -= 1;
		if (x > arr[m]) m += 1;
	}
	cout << m;*/

	if (l > r) return -1;
	int m = (l + r) * 1.0 / 2;
	if (x == arr[m]) return m;
	if (x > arr[m]) {
		l = m + 1;
	}
	if (x < arr[m]) {
		r = m - 1;
	}
	return TimKiemNhiPhan(arr, l, r, x);
}

void CaSiLeRo(int n, vector<pair<int,int>> arr) {
	sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	});
	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		int sum = 1, tam = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[tam].second < arr[j].first) {
				sum++;
				tam = j;
			}
		}
		if (max < sum) max = sum;
	}
	cout << max;
}

void in_theo_khuon_dang(int n, vector<int> arr) {
	sort(arr.begin(), arr.end());
	int size = arr.size();
	int j = size - 1;
	for (int i = 0; i < size; i++) {
		if (size % 2 == 0) { // so chan
			if (i > j) break;
		}
		else { // so le
			if (i == j) {
				cout << arr[i];
				break;
			}
		}
		cout << arr[j--] << " " << arr[i] << " ";
	}
}

void counting_sort(int n, vector<int> arr) {
	map<int, int> m;
	vector<int> arrtam;
	for (auto item : arr) m[item]++;
	for (auto item : m) {
		while (item.second > 0) {
			item.second--;
			arrtam.push_back(item.first);
		}
	}
	for (auto item : arrtam) cout << item << ' ';
}

void cap_co_tong_bang_k(int n, int k, vector<int> arr) {
	int sum = 0;
	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < n; i++) {
		if (arr[i] > k) break;
		for (int j = n - 1; j > i; j--) {
			if (arr[i] + arr[j] == k) sum++;
		}
	}

	cout << sum;
}

void cap_co_tong_nho_hon_k(int n, int k, vector<int> arr) {
	sort(arr.begin(), arr.end());
	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] == k) break;
		for (int j = n - 1; j > i; j--) {
			if (arr[i] + arr[j] < k) sum++;
		}
	}

	cout << sum;
}

void cap_co_tong_lon_hon_k(int n, int k, vector<int> arr) {
	sort(arr.begin(), arr.end());
	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (arr[i] + arr[j] > k) sum++;
		}
	}

	cout << sum;
}
int main()
{	//7, 1, 6, 2, 5, 3, 4 
	//1 ,6, 9 ,4 ,3 ,7 ,8, 2 
	vector<int> arr1 = {1,2,3,4,5,6,7};
	vector<int> arr2 = {2,2,2,2};
	vector<int> arr3 = { 100,200,300,400,500,600,700,800 };
	vector<int> arr4 = { 1,2,3,4,5 };
	vector<pair<int, int>> arr5 = { {5,6} , {1,2} ,{7,8},{3,4} };
	cap_co_tong_bang_k(arr2.size(), 4, arr2);
	/*int T = 4;
	int N, K, tam;
	vector<vector<int>> arr(T);
	vector<vector<int>> arrN_K(T);
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		arrN_K[i].push_back(N);
		arrN_K[i].push_back(K);
		for (int j = 0; j < N; j++) {
			cin >> tam;
			arr[i].push_back(tam);
		}
	}
	for (int i = 0; i < T; i++) {
		ProblemsA(arrN_K[i][0], arrN_K[i][1], arr[i]);
	}*/
	
    return 0;
}