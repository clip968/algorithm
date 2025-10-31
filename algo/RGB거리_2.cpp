#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<vector<int>> dp;

int RGB(int first_color, int n) {
    int result = INT_MAX;
    dp.assign(1005, vector<int>(3));
    dp[0][first_color] = v[0][first_color];
    for(int i=0;i<3;i++){
        if(i != first_color) {
            dp[0][i] = 1e9;
        }
    }
    for(int i=1;i<n-1;i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + v[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + v[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + v[i][2];
    }

    for(int i=0;i<3;i++){
        if(first_color != i) {
            result = min(result, min(dp[n-2][(i+1)%3], dp[n-2][(i+2)%3]) + v[n-1][i]);
        }
    }

    return result;

}

int main(){
    int n; scanf("%d", &n);
    int answer=INT_MAX;

    v.assign(n, vector<int>(3, 0));
    dp.assign(1005, vector<int>(3));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &v[i][j]);
        }
    }

    for(int color = 0;color<3;color++){
        answer = min(answer, RGB(color, n));
    }

    printf("%d", answer);


}