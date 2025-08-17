#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

int DemSoPhanTuKhacNhauTrongSet(vector<int>v,set<int>s) {
    int sum = 0;
    for (auto item : v) {
        s.insert(item);
    }
    for (auto item : s) {
        sum++;
    }
    return sum;
}
void TruyVanTrongSet(vector<int> v, int tv) {
    set<int>s;
    for (auto item : v) s.insert(item);
    if (s.find(tv) == s.end()) cout << "NO";
    else cout << "YES";
}

void Lap(int L,vector<int>v) {
    set<int>s; 
    for (auto item : v) s.insert(item);
    int tv;
    for (int i = 0; i < L; i++) {
        cin >> tv;
        TruyVanTrongSet(v, tv);
    }
}

void LietKePhanTuKhacNhau(vector<int> v) {
    set<int> s;
    for (auto item : v) {
        if (s.count(item) == 0) {
            cout << item;
            s.insert(item);
        }
    }
}

void LietKePhanTuKhacNhauNhoDenLon(vector<int>v) {
    set<int>s;
    for (auto item : v) {
        s.insert(item);
    }
    for (auto item : s) {
        cout << item;
    }
}

void DemSoPhanTuKhacNhauTrongMap(vector <int>v) {
    map <int, int> m;
    for (auto item : v) {
        m[item] = 1;
    }
    cout << m.size();
}

void DemLanXuatHien(vector <int>v) {
    map <int, int> m;
    for (auto item : v) {
        m[item]++;
    }
    for (auto item : m) {
        cout << item.second << " ";
    }
}

void DemLanXuatHienVaGiaTri(vector <int>v) {
    map <int, int> m;
    for (auto item : v) {
        m[item]++;
    }
    for (auto item : m) {
        cout << item.first << "=" << item.second << " ";
    }
}

void DemLanXuatHienCuaKyTu(string str) {
    map <char, int> m;
    for (auto item : str) {
        m[item]++;
    }
    for (auto item : m) {
        cout <<item.second << " ";
    }
}

void DemLanXuatHienCuaKyTuVaKyTu(string str) {
    map <char, int> m;
    for (auto item : str) {
        m[item]++;
    }
    for (auto item : m) {
        cout << item.first << "=" << item.second << " ";
    }
}

void TapHopCuaHaiMang(vector<int> v1, vector<int> v2) {
    map <int, int> m;
    int min = INT_MAX;
    for (auto item : v1) {
        m[item]++;
    }
    for (auto item : v2) {
        m[item]++;
    }
    for (auto item : m) {
        if (min > item.second) {
            min = item.second;
        }
    }
    for (auto item : m) {
        if (item.second == min) {
            cout << item.first;
        }
    }
}

void TapGiaoCuaHaiMang(vector<int> v1, vector<int> v2) {
    map<int, int> m;
    for (auto item : v1) m[item]++;
    for (auto item : v2) m[item]++;
    for (auto item : m) cout << item.first;
}

int NoiDay(vector<int> v1) {
    priority_queue<int,vector<int>, greater<int> > pq;
    int sum = 0;
    int tam;
    for (auto item : v1) pq.push(item);
    
    tam = pq.top();
    pq.pop();
    sum += tam + pq.top();
    pq.pop();

    size_t Size = pq.size();
    for (int i = 0; i < Size; i++) {
            sum += pq.top();
            pq.pop();
    }
    return sum;
}

int GiaTriNhoNhatCuaXau(string str,int k) {
    priority_queue<int> pq;
    int sum = 0;
    int tam, gtri;
    map<char, int> m;

    for (auto item : str) m[item]++;
    for (auto item : m) pq.push(item.second);
    
    while (k > 0) {
        tam = pq.top();
        tam--;
        pq.pop();
        pq.push(tam);
        k--;
    }
    size_t Size = pq.size();
    for (int i = 0; i < Size; i++) {
        gtri = pq.top();
        sum += pow(gtri, 2);
        pq.pop();
    }
    return sum;
}

int main()
{
    vector<int> v1 = { 4,3,2,6 };
    vector<int> v2 = { 3,5,6,7,8 };
    
    int k; cin >> k;
    string str; cin >> str;
    int sum =GiaTriNhoNhatCuaXau(str,k);
    cout << sum;
    return 0;
}

