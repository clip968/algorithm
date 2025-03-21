#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> arr_index;
tuple<int, int, int> kadane(int low, int high, vector<int> arr){
    int max_arr{};
    int curr_max = INT_MIN / 2;
    int start{}, end{};
    int result_s{}, result_e{};
    for(int i=low;i<=high;i++){
        if(arr[i] != 0 && max_arr + arr[i] < arr[i]){
            max_arr = arr[i];
            start = end = i;
        }
        else{
            max_arr += arr[i];
            end = i;
        }
        if(curr_max < max_arr){
            curr_max = max_arr;
            result_s = start;
            result_e = end;
        }
            
        }
    
    return {curr_max, result_s, result_e};
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        vector<int> arr;
        for(int i=0;i<n;i++){
            int temp; scanf("%d", &temp);
            arr.push_back(temp);
        }

        tuple<int, int, int> result = kadane(0, arr.size()-1, arr);
        if(get<0>(result) < 0){
            printf("0 -1 -1\n");
        }
        else{
        printf("%d %d %d\n", get<0>(result), get<1>(result), get<2>(result));

        }
        

    }
}