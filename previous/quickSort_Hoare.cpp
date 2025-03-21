#include<bits/stdc++.h>
using namespace std;
int hoare_sort_count{}, lomuto_sort_count{};
int hoare_swap_count{}, lomuto_swap_count{};
int partition_Lomuto(vector<int>& A, int low, int high);
int partition_Hoare(vector<int>& A, int low, int high);

void quicksort_hoare(vector<int>& A, int low, int high){
    if (low >= high) return;
    int p = partition_Hoare(A, low, high);
    quicksort_hoare(A, low, p);
    quicksort_hoare(A, p+1, high);
}

int partition_Hoare(vector<int>& A, int low, int high){
    int pivot = A[low];
    int i = low - 1;
    int j = high + 1;
    while(true)
    {
        hoare_sort_count+=2;
        while (A[++i] < pivot)hoare_sort_count++; // 비교(comparison) 연산자 ‘<’
        while (A[--j] > pivot)hoare_sort_count++; // 비교(comparison) 연산자 ‘<’
        if (i < j){
            hoare_swap_count++;
            swap(A[i], A[j]);
        }
         // swap 연산
        else return j;
        }
    }

void quicksort_lomuto(vector<int>& A, int low, int high){
    if (low >= high) return;

    int p = partition_Lomuto(A, low, high);
    quicksort_lomuto(A, low, p-1);
    quicksort_lomuto(A, p+1, high);
}

int partition_Lomuto(vector<int>& A, int low, int high){
    int pivot = A[low];
    int j = low;
    for (int i = low+1;i<=high;i++) {
        lomuto_sort_count++;
        if (A[i] < pivot) {  // 비교(comparison) 연산자 ‘<’
        j = j + 1;
        lomuto_swap_count++;
        swap(A[i], A[j]);
        }
    }
     // swap 연산
    int pivot_pos = j;
    lomuto_swap_count++;
    swap(A[pivot_pos], A[low]); // swap 연산
    return pivot_pos;
    }

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        hoare_sort_count=0;
        hoare_swap_count=0;
        lomuto_sort_count=0;
        lomuto_swap_count=0;
        vector<int> arr;
        vector<int> arr2;
        // printf("%d\n", n);
        for(int i{};i<n;i++){
            int temp;
            scanf("%d", &temp);
            arr.push_back(temp);
            arr2.push_back(temp);
        }

        // for(int i{};i<arr.size();i++){
        //     printf("%d ", arr[i]);
        // }

        quicksort_hoare(arr, 0, n-1);
        quicksort_lomuto(arr2, 0, n-1);

        printf("%d %d %d %d\n", hoare_swap_count, lomuto_swap_count, hoare_sort_count, lomuto_sort_count);
    }
}

