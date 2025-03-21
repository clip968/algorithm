#include<bits/stdc++.h>
using namespace std;

int cross_val(int low, int high, vector<int> arr){
    int mid = (low + high) / 2;
    int left_max{INT_MIN}, right_max{INT_MIN};
    int sum{};

    for(int i=mid;i >= low;i--){
        sum += arr[i];
        if(sum > left_max){
            left_max = sum;
        }
    }
    sum = 0;
    for(int i = mid+1;i<=high;i++){
        sum += arr[i];
        if(sum > right_max){
            right_max = sum;
        }
    }
    
    return left_max + right_max;
}

int divide(int low, int high, vector<int> arr){
    if(low == high) return arr[low];
    int mid = (low + high) / 2;

    int left_max = divide(low, mid, arr);
    int right_max = divide(mid+1, high, arr);
    int cross_max = cross_val(low, high, arr);

    return max({left_max, right_max, cross_max});
}

int main(){
    int t{};
    scanf("%d", &t);

    while(t--){
        int n; scanf("%d", &n);
        vector<int> arr;

        for(int i{};i<n;i++){
            int temp;
            scanf("%d", &temp);
            arr.push_back(temp);
        }

        // for(int k : arr){
        //     printf("%d", k);
        // }

        // 구간합 함수
        int result = divide(0, arr.size()-1, arr);

        printf("%d\n", result);
    }

}