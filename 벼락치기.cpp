#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    scanf("%d %d", &n, &t); 

    vector<int> dp(t+1, 0);

    for(int i{};i<n;++i){
        int study_time, score;
        scanf("%d %d", &study_time, &score);

        for(int j{t};j>=study_time;j--){
            dp[j] = max(dp[j], dp[j-study_time] + score);
            // printf("{%d, %d}", j, dp[j]);
        }
        // printf("\n");
    }

    printf("%d\n", dp[t]);
}