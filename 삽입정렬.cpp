#include<bits/stdc++.h>
using namespace std;

void insertSort(int a[], int n){
    int value, j, result_a{}, result_b{};
    for(int i = 1;i < n;i++){
        value = a[i];
        for(j = i - 1;j >= 0;j--){
            result_a += 1;
            if(a[j] > value) {
                a[j + 1] = a[j];
                result_b += 1;
            }
            else break;
        }
        a[j + 1] = value;
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

        insertSort(arr, n);
    }
    
}