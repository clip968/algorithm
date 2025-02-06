#include<bits/stdc++.h>
using namespace std;

int calculate(vector<int> arr){
    int max_result{1};
    int curr_result{1};

    for(int i = 1;i<arr.size();i++){
        if(arr[i] > arr[i-1]){
            curr_result++;
        }
        else{
            max_result = max(max_result, curr_result);
            curr_result = 1;
        }
    }

    return max(curr_result, max_result);
}


int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        vector<int> arr;
        for(int i=0;i<n;i++){
            int temp; scanf("%d", &temp);
            arr.push_back(temp);
        }
        int result = calculate(arr);
        printf("%d\n", result);
    }
}