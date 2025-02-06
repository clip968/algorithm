#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    int min;
    for(int i=0;i<n-1;i++){
        min = i;
        for(int j=i+1;j<n;j++){
            countCmpOps+=1;
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        if(i != min){
            countSwaps += 1;
            swap(arr[min], arr[i]);
        }
    }
    
    printf("%d %d\n", countCmpOps, countSwaps);
    
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            int temp; scanf("%d", &temp);
            arr[i]=temp;
        }

        // for(int k : arr){
        //     printf("%d ", k);
        // }
        
        selectionSort(arr, n);
    }
}