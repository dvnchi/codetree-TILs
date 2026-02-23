#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[100000];

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int max_val = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        // 입력받으면서 가장 큰 값을 찾습니다. (몇 번 반복할지 결정하기 위함)
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // pos: 현재 검사하는 자릿수 (1, 10, 100 ...)
    // max_val / pos > 0 일 때까지만 반복하면 가장 큰 수의 최대 자릿수까지만 정렬합니다.
    for (long long pos = 1; max_val / pos > 0; pos *= 10) {
        
        // 0~9까지 숫자를 담을 10개의 버킷 생성
        vector<int> buckets[10];
        
        // 1. 현재 자릿수(pos)를 기준으로 각 숫자를 알맞은 버킷에 넣기
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / pos) % 10;
            buckets[digit].push_back(arr[i]);
        }
        
        // 2. 버킷에 들어간 순서대로 다시 원본 배열(arr)에 덮어쓰기
        int idx = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                arr[idx++] = buckets[i][j];
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
  
    return 0;
}