#include <iostream>
#include <algorithm> // swap 함수 사용

using namespace std;

int n;
int arr[100000];

void quick_sort(int low, int high) {
    if (low >= high) return;

    int pivot = arr[(low + high) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) break;

        swap(arr[i], arr[j]);
    }

    quick_sort(low, j);
    quick_sort(j + 1, high);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quick_sort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}