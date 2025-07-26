#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n; scanf("%d", &n);
        vector<int> coin(n);
        for(int i{};i<n;++i){
            scanf("%d", &coin[i]);
        }

        int limit;
        scanf("%d", &limit);

        vector<int> dp(limit+1, 0);

        dp[0] = 1;
        for(auto& k : coin){
            for(int i{k};i<=limit;++i){
                dp[i] += dp[i-k];
            }
        }

        printf("%d\n", dp[limit]);
    }
}