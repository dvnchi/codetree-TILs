#include <iostream>
#include <algorithm> // swap 함수 사용

using namespace std;

int n;
int arr[100000];

// 주어진 노드(i)를 루트로 하는 서브트리를 Max-Heap으로 만드는 함수
void heapify(int n, int i) {
    int largest = i;         // 현재 노드를 가장 큰 값으로 임시 설정
    int left = 2 * i + 1;    // 왼쪽 자식 인덱스 (0-based 기준)
    int right = 2 * i + 2;   // 오른쪽 자식 인덱스 (0-based 기준)

    // 왼쪽 자식이 존재하고, 부모보다 크다면 largest 업데이트
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 오른쪽 자식이 존재하고, 현재 가장 큰 값보다 크다면 largest 업데이트
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 자식 노드 중 더 큰 값이 존재해서 largest가 변경되었다면
    if (largest != i) {
        swap(arr[i], arr[largest]); // 값을 교환
        // 교환되어 내려간 위치에서 다시 heapify 연쇄 호출
        heapify(n, largest);
    }
}

// 힙 정렬 메인 함수
void heap_sort() {
    // 1. 초기 배열을 Max-Heap으로 만들기 (Build Heap)
    // 리프 노드를 제외한 가장 마지막 내부 노드부터 역순으로 올라가며 heapify 수행
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(n, i);
    }

    // 2. 힙에서 하나씩 원소를 빼면서 정렬하기
    for (int i = n - 1; i > 0; i--) {
        // 현재 힙의 루트(최댓값)를 배열의 맨 끝(정렬된 위치)으로 보냄
        swap(arr[0], arr[i]);
        
        // 맨 끝으로 보낸 원소는 제외하고(크기를 i로 줄임), 루트 노드부터 다시 heapify 수행
        heapify(i, 0);
    }
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heap_sort();

    // 결과 출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}