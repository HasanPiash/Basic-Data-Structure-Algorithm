#include <bits/stdc++.h>
using namespace std;
int* sort_it(int size) {
    int* arr = new int[size];  
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + size, greater<int>());
    return arr;  
} 
int main() {
    int N;
    cin >> N;
    int* sorted_arr = sort_it(N); 
    for (int i = 0; i < N; i++) {
        cout << sorted_arr[i] << " ";
    }
    delete[] sorted_arr;  
    return 0;
}
