#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<vector<int>> dp;
int main(){
    int n; scanf("%d", &n);

    v.assign(n, vector<int>(3, 0));
    dp.assign(1005, vector<int>(3));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &v[i][j]);
        }
    }

    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    for(int i=1;i<n;i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + v[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + v[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + v[i][2];
    }

    printf("%d", min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])));

    
    // for(auto k : v) {
    //     for(int i : k){
    //         printf("%d ", i);
    //     }
    //     printf("\n");
    // }


    
}