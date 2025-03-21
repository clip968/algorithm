#include<bits/stdc++.h>
using namespace std;

tuple<int, int, int> kadane(int low, int high, vector<int> arr){
    int result_low{}, result_high{};
    int curr_max{};
    int start{}, end{};
    int max_arr = INT_MIN / 2;
    
    for(int i{low};i<=high;i++){
        if(arr[i] != 0 && curr_max + arr[i] < arr[i]){
            curr_max = arr[i];
            start = i;
            end = i;
        }

        else{
            curr_max += arr[i];
            end = i;
        }
        if(max_arr < curr_max){
            max_arr = curr_max;
            result_low = start;
            result_high = end;
        }
    }

    return {result_low, result_high, max_arr};
}

int main(){
    int t; scanf("%d", &t);

    while(t--){
        int n; scanf("%d", &n);
        vector<int> arr(n, 0);
        for(int i{};i<n;i++){
            scanf("%d", &arr[i]);
        }

        // kadane
        tuple<int, int, int> result = kadane(0, arr.size()-1, arr);

        if(get<2>(result) < 0){
            printf("0 -1 -1\n");
        }
        else{
            printf("%d %d %d\n", get<2>(result), get<0>(result), get<1>(result));
        }
    }
}