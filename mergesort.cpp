#include<bits/stdc++.h>
using namespace std;
int n;
int counter;

void merging(int arr[], int low, int high)  {
    int temp[n];
    int k, l, h;
    int mid = (low + high)/2;
    for(int i{};i<n;i++){
        temp[i] = arr[i];
    }

    k = l = low;
    h = mid+1;

    while(l<=mid && h <= high){
        counter++;
        if(temp[l] < temp[h]){
            arr[k++] = temp[l++];
        }
        else{
            arr[k++] = temp[h++];
        }
    }
    while(l <= mid){
        arr[k++] = temp[l++]; 
    }
    while(h <= high){
        arr[k++] = temp[h++];
    }
}

void mergeSort(int arr[], int low, int high){
    if (low == high) return;
    int mid = (low + high)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merging(arr, low, high);
}

int main(){
    int t; scanf("%d", &t);

    while(t--){
        counter = 0;
        n = 0;scanf("%d", &n);
        int arr[n]{};

        for(int i{};i<n;i++){
            scanf("%d", &arr[i]);
        }

        //mergeSort
        mergeSort(arr, 0, n-1);

        printf("%d\n", counter);
    }
}