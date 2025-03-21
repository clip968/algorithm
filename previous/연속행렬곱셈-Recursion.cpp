#include<bits/stdc++.h>
using namespace std;
int arr[11];

int f(int i, int j){
    int result = INT_MAX;
    if(i == j){
        return 0;
    }
    for(int k = i;k < j;k++){
        result = min(f(i, k) + f(k+1, j) + arr[i-1]*arr[k]*arr[j], result);
    }
    return result;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        for(int i= 0;i<=n;i++){
            scanf("%d", &arr[i]);
        }

        int result = f(1, n);
        printf("%d\n", result);
    }
}