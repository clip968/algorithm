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

void mergeSortIterative(int v[], int n)
{
    int size = 1;
    while (size < n)
    {
    for (int i = 0; i < n; i += 2 * size){
        int low = i;
        int mid = low + size - 1;
        int high = min(i + 2 * size - 1, n - 1);
        if (mid >= n - 1) break;// merge할 subarray가 1개일 경우
            merge(v, low, mid, high);
        }
    size *= 2;
    }
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
        
        mergeSortIterative(arr, n);
        
        printf("%d\n", result);
        result = 0;
    }

}


