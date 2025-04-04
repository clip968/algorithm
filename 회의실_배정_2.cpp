#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    int dp[30];
    priority_queue<pair<pair<int, int>, int>> pq;
    for(int i{};i<n;++i){
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        pq.push({{start, end}, weight});
        // dp[i] = weight;
    }

    int idx{0};
    while(!pq.empty()){
        int curr_start = pq.top().first.first;
        int curr_end = pq.top().first.second;
        int curr_weight = pq.top().second;
        pq.pop();
        if(idx == 0){
            dp[idx] = curr_weight;
            idx++;
        }
        else if(idx == 1){
            dp[idx] = max(dp[idx-1], curr_weight);
            idx++;
        }
        else{ // idx == 2 부터
            dp[idx] = max(dp[idx-2]+curr_weight, dp[idx-1]);
            idx++;
        }
    }
    printf("%d", dp[n-1]);
}