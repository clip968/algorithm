#define MAX_SIZE 100
#include<bits/stdc++.h>
using namespace std;
int result{};

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int tmp[MAX_SIZE];

    for(i=low; i<=high; i++){
        tmp[i] = a[i];
    }
    i = k = low;
    j = mid+1;
    while(i<=mid && j<=high){
        result += 1;
        if(tmp[i] <= tmp[j]){
            a[k++] = tmp[i++];
        } // <---- 핵심연산자(비교연산자)
        else a[k++] = tmp[j++];
    }
        while(i<=mid) a[k++] = tmp[i++];
        while(j<=high) a[k++] = tmp[j++];
    
}

void mergeSort(int v[], int low, int high)
{
    int mid;
    if(low == high)
        return; /* base case */
    mid = (low + high) / 2;

    mergeSort(v, low, mid);
    mergeSort(v, mid+1, high);
    merge(v, low, mid, high);
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        int arr[MAX_SIZE]{};
        for(int i{}; i<n;i++){
            int temp;
            scanf("%d", &temp);
            arr[i] = temp;
        }
        
        mergeSort(arr, 0, n-1);
        
        printf("%d\n", result);
        result = 0;
    }

}

