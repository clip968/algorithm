#include<bits/stdc++.h>
using namespace std;
int cross_val(int low, int high, vector<int> arr){
    int mid = (low + high) / 2;
    int sum = 0;
    int left_sum{}, right_sum{};

    for(int i=mid;i >= low;i--){
        sum += arr[i];
        if(sum > left_sum){
            left_sum = sum;
            
        }
    }

    sum = 0;

    for(int i=mid+1;i<=high;i++){
        sum += arr[i];
        if(sum > right_sum){
            right_sum = sum;
        }
    }

    return left_sum + right_sum;

}   

int divide(int low, int high, vector<int> arr){
    if (low == high) return arr[low];
    int mid = (low + high) / 2;
    
    int left_max = divide(low, mid, arr);
    int right_max = divide(mid + 1, high, arr);
    int middle_max = cross_val(low, high, arr);

    return max({left_max, right_max, middle_max});
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

        int result = divide(0, arr.size()-1, arr);
        printf("%d\n", result);
        

    }
}