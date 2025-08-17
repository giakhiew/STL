#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//grok.com
int LinearSearch(vector<int> arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (x = arr[i]) {
            return i;
        }
    }
    return -1;
}

int BidirectionalLinearSearch(vector<int> arr, int x) { //tim kiem tuyen tinh 2 dau
    int j = arr.size() - 1;
    for (int i = 0; i < j; i++) {
        if (x = arr[i]) return i;
        else if (x = arr[j]) return j;
        j--;
    }
    return -1;
}

int SentinelLinearSearch(vector<int> arr, int x) {
    arr.push_back(x);
    int i = 0;
    while (arr[i] != x) {
        i++;
    }
    arr.pop_back();
    if (i < arr.size()) return i;
    else return -1;
}

int SortedLinearSearch(vector<int> arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x)  return i;
        else if (arr[i] > x) return -1;
    }
    return -1;
}

int JumpSortedLinearSearch(vector<int> arr, int x) {
    int Size = arr.size();
    int jump = sqrt(Size);
    int curr = 0;

    for (int i = 0; i < Size; i += jump) {
        if (arr[i] == x) return i;
        else if (arr[i] > x) {
            curr = i;
            break;
        }
    }

    for (int i = curr - jump; i < curr; i++) {
        if (arr[i] == x) return i;
    }

    return -1;
}

int BinarySearch(vector<int> arr, int x, int l, int r) {
    int mid = 0;
    //CACH1: VONG LAP
    //while (l <= r) { 
    //    mid = (l + r) / 2;
    //    if (arr[mid] == x) return mid;
    //    else if (arr[mid] > x) r = mid - 1;
    //    else if (arr[mid] < x) l = mid + 1;
    //}
    //return -1;
    mid = (l + r) / 2;
    if (l > r) return -1;

    if (arr[mid] == x) return mid;
    else if (arr[mid] > x) r = mid - 1;
    else if (arr[mid] < x) l = mid + 1;
    return BinarySearch(arr, x, l, r);
}

int FirstBinarySearch(vector<int> arr, int x, int l, int r) {
    int mid = 0;
    int tam = -1;
    while (l <= r) { 
        mid = (l + r) / 2;
        if (arr[mid] == x) {
            r = mid - 1;
            tam = mid;
        }
        else if (arr[mid] > x) r = mid - 1;
        else if (arr[mid] < x) l = mid + 1;
    }
    return tam;
}

int LastBinarySearch(vector<int> arr, int x, int l, int r) {
    int mid = 0;
    int tam = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (arr[mid] == x) {
            l = mid + 1;
            tam = mid;
        }
        else if (arr[mid] > x) r = mid - 1;
        else if (arr[mid] < x) l = mid + 1;
    }
    return tam;
}

int main()
{
    vector<int> arr1 = {1,2,2,3,3,3,4,5,6};
    int check = LastBinarySearch(arr1, 3, 0, 8);
    cout << check;
    return 0;
}
