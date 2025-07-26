#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector<pair<int, int>> v(n);
    int total_cost{};

    for(int i{};i<n;++i){
        int byte;
        scanf("%d", &byte);

        v[i].first = byte;
    }

    for(int i{};i<n;++i){
        int cost;
        scanf("%d", &cost);
        v[i].second = cost;
        total_cost += cost;
    }

    // sort(v.begin(), v.end());
    vector<int> dp(total_cost+1, 0);

    for(int i{};i<n;++i){
        int byte = v[i].first;
        int cost = v[i].second;

        for(int j{total_cost};j>=cost;--j){
            dp[j] = max(dp[j], dp[j-cost] + byte);
            // printf("%d ", dp[j]);
        }
        // printf("\n\n");
    }

    int ans{total_cost};
    for(int i{};i<=total_cost;++i){
        if(dp[i] >= m) {
            ans = i;
            printf("%d\n", ans);
            return 0;
        }
    }


}