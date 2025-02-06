#include<bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n){
    int min, max, tmp, result_a{}, result_b{};
    for(int i = 0;i < n - 1;i++){
        min = i;
        
        for(int j = i + 1;j < n;j++){
            result_a += 1;
            if(a[j] < a[min]){
                min = j;
            }
        }
        if (i != min){
            result_b += 1;
            swap(a[min], a[i]);
        }
    }
    cout << result_a << " " << result_b << "\n";
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n]{};

        for(int i = 0;i < n;i++){
            int tmp;
            scanf("%d", &tmp);
            arr[i] = tmp;
        }

        selectionSort(arr, n);
    }
    
}