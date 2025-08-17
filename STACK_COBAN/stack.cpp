#include <stack>
#include <iostream>
#include<vector>
#include<string>
using namespace std;


//for (int i = 1; i <= 5; i++) s.push(i);
//s.push(100);
//cout << s.top() << endl;
//s.pop();
//cout << s.empty() << endl;
//cout << s.size() << endl;
//system("pause");

void ChuoiDaoNguocBangStack(stack<char> a,string A) {
    size_t Size = A.size();
    for (int i = 0; i < Size; i++) a.push(A[i]);
    for (int i = 0; i < Size; i++) {
        cout << a.top();
        a.pop();
    }
}

void ChuoiNhiPhan(stack<int>a,int A) {
    while (A > 0) {
        a.push(A % 2);
        A /= 2;
    }
    ////17/2 = 8 du 1 8/2 = 4 du 0 4/2 = 2 du 0 2/2 = 1 du 0
    size_t Size = a.size();
    for (int i = 0; i < Size; i++) {
        cout << a.top();
        a.pop();
    }
}

void NgoacDoiXung(stack<char>a, string A) {
    size_t Size = A.size();
    int sum = 0;
    int sum1 = 0;
    if (Size % 2 != 0) cout << "NO";
    else {
        for (int i = 0; i < Size; i++) {
            if (A[i] == '(' || A[i] == '[' || A[i] == '{') {
                a.push(A[i]);
                sum++;
            }
            else {
                if (A[i] == ')' && a.top() == '(') {
                    a.pop(); sum1++;
                }
                else if (A[i] == ']' && a.top() == '[') {
                    a.pop(); sum1++;
                }
                else if (A[i] == '}' && a.top() == '{') {
                    a.pop(); sum1++;
                }
            }
            if (a.empty() == true) cout << "YES";
            if (sum != sum1) cout << "NO";
        }
    }
}
//1 2 3 4 3
void XetVongTron(stack<int> a, vector<int> A) {
    vector<int> b;
    size_t Size = A.size();
    for (int i = 0; i < Size-1; i++) {
        if (a.empty() == true) {
            if (A[i] < A[i + 1]) {
                a.push(A[i + 1]);
                b.push_back(A[i + 1]);
            }
            else if (A[i] > A[i + 1]) {
                a.push(A[i]);
                b.push_back(A[i]);
            }
        }
        else {
            if (A[i]<A[i + 1] && A[i + 1]>a.top()) {
                a.push(A[i + 1]);
                b.push_back(A[i + 1]);
            } // 1 2 3 4 3
            else if (A[i] > A[i + 1] && A[i] > a.top()) {
                a.push(A[i]);
                b.push_back(-1);
            }
        }
        cout << b[i];
    }
}

int main()
{
    /*string a; getline(cin,a);*/
    stack <char> a; stack<int>c;
    vector<int>d = {1,2,1 };
    /*int b; cin >> b;*/
    XetVongTron(c, d);
    return 0;
}
