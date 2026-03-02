#include <iostream>

using namespace std;

int n;
int arr[100000];
int merged_arr[100000]; // 메모리 초과 방지를 위해 전역 변수로 이동

// 1. function 키워드 제거, void 및 타입 명시
void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            merged_arr[k] = arr[i];
            k += 1;
            i += 1; // 2. 왼쪽 값을 가져왔으므로 i를 증가 (무한루프 해결)
        } else {
            merged_arr[k] = arr[j];
            k += 1;
            j += 1;
        }
    }

    while (i <= mid) {
        merged_arr[k] = arr[i];
        k += 1;
        i += 1;
    }

    while (j <= high) {
        merged_arr[k] = arr[j];
        k += 1;
        j += 1;
    }

    // 3. 쉼표를 세미콜론으로 수정
    for (int k = low; k < high + 1; k++) {
        arr[k] = merged_arr[k];
    }
}

// 4. function 키워드 제거, void 및 타입 명시
void merge_sort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        
        // 5. 범위 수정 및 오타(.) 수정
        merge_sort(arr, low, mid); 
        merge_sort(arr, mid + 1, high);
        
        merge(arr, low, mid, high);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 6. 배열의 마지막 인덱스는 n-1 이므로 n-1을 전달하고 세미콜론 추가
    merge_sort(arr, 0, n - 1);

    // 정렬이 잘 되었는지 확인하기 위한 출력문
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}