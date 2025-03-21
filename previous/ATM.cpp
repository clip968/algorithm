#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    vector<int> arr(n);
    int result{}, temp{};

    for(int i{};i<n;i++){
        scanf("%d", &arr[i]);
    }

    sort(arr.begin(), arr.end());

    for(int i{};i<n;i++){
        // printf("%d",arr[i]);
        temp += arr[i];
        // printf("%d", temp);
        result += temp;
    }

    printf("%d", result);

}