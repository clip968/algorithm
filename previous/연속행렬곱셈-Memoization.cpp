#include<bits/stdc++.h>
using namespace std;
int arr[101];
vector<vector<int>> memo;
int f(int i, int j){
    
    int result = INT_MAX;
    if(i == j) {
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    for(int k = i;k < j;k++){
        result = min(f(i, k) + f(k+1, j) + arr[i-1]*arr[k]*arr[j], result);
    }
    memo[i][j] = result;
    return memo[i][j];
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        for(int i= 0;i<=n;i++){
            scanf("%d", &arr[i]);
        }

        memo = vector<vector<int>>(n+1, vector<int>(n+1, -1));

        int result = f(1, n);
        printf("%d\n", result);
    }
}