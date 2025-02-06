#include<bits/stdc++.h>
using namespace std;

void calculator(vector<int>& arr, int div){
    int size = arr.size();
    vector<int> output(size);
    int count[10]={0};

    for(int i{};i<size;i++){
        int digit = (arr[i]/div) % 10;
        count[digit]++;
    }

    for(int i{1};i < 10;i++){
        count[i] += count[i-1];
    }

    for(int i=size-1;i>=0;i--){
        int digit = (arr[i]/div) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i{};i<size;i++){
        arr[i] = output[i];
    }
}

void radix_sort(vector<int>& arr){
    int maxVal = *max_element(arr.begin(), arr.end());
    int size = arr.size();
    for(int i{1};maxVal / i > 0;i *= 10){
        calculator(arr, i);
    }
}

int main(){
    int t; scanf("%d", &t);

    while(t--){
        int n; scanf("%d", &n);

        vector<int> arr(n, 0);

        for(int i{};i<n;i++){
            int temp;
            scanf("%d", &temp);
            arr[i] = temp;
        }
        
        // radix Sort
        radix_sort(arr);

        for(int i{};i<n;i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}