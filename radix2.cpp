#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Counting Sort를 사용하여 특정 자릿수 기준으로 정렬합니다.
void countingSort(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    int count[10] = {0};

    // 현재 자릿수를 기준으로 counting
    for (int i = 0; i < arr.size(); i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }
    
    // 누적 합 계산
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 결과 배열 생성
    for (int i = arr.size() - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // 정렬된 결과를 원본 배열에 복사
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void radixSortLeftToRight(vector<int>& arr) {
    // 배열의 최대값을 찾습니다.
    int maxVal = *max_element(arr.begin(), arr.end());

    // 각 자릿수를 기준으로 Counting Sort를 수행합니다.
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {239, 234, 879, 878, 123, 358, 416, 317, 137, 225};
    radixSortLeftToRight(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
