#include<bits/stdc++.h>
using namespace std;
int arr[101];
vector<vector<int>> memo;

int memoization(int m, int n){
    int result = INT_MAX;
    if(m == n){
        return 0;
    }
    if(memo[m][n] != -1) return memo[m][n];

    for(int i{m};i<n;i++){
        result = min(memoization(m, i) + memoization(i+1, n) + arr[m-1]*arr[i]*arr[n], result);
    }
    memo[m][n] = result;

    return memo[m][n];

}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        
        int n; scanf("%d", &n);
        memo.clear();
        memo.resize(n+1, vector<int>(n+1, -1));
        for(int i{};i<=n;i++){
            int temp; scanf("%d", &temp);
            arr[i] = temp;
        }

        int result = memoization(1, n);
        printf("%d\n", result);


    }
}