#include<bits/stdc++.h>
using namespace std;
int arr[101];
int n;
vector<vector<int>> dp;
int p[101][101]{};
int f(){
    // printf("%d", n);
    int result = INT_MAX;
    for(int diagnol = 1; diagnol <= n - 1; diagnol++){
        for(int i = 1; i <= n - diagnol; i++){
            int j = i + diagnol;
            int result = INT_MAX; 
            for(int k = i; k <= j - 1; k++){
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                if (cost < result) {
                    result = cost;
                    p[i][j] = k;
                }
            }
            dp[i][j] = result; 
        }
    }
            
   
    return dp[1][n];
}

void order(int i, int j){
    if(i == j){
        printf("M%d",i);
    }
    else{
        int k = p[i][j];
        printf("(");
        order(i, k);
        order(k+1, j);
        printf(")");
    }
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i= 0;i<=n;i++){
            scanf("%d", &arr[i]);
        }
        dp = vector<vector<int>>(n+1, vector<int>(n+1, 0));
        memset(p, 0, sizeof(p));
        for(int i=0;i<=n;i++){
            dp[i][i] = 0;
        }
       
        int result = f();
        order(1, n);
        
        printf("\n%d\n", result);
    }
}