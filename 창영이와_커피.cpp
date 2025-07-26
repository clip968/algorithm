#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> caffine(n);
    for(int i{};i<n;++i){
        scanf("%d", &caffine[i]);
    }

    sort(caffine.begin(), caffine.end());

    vector<int> dp(m+1, INT_MAX/2);

    dp[0] = 0;
    for(int i{};i<n;++i){
        for(int j{m};j>=caffine[i];--j){
            if(dp[j - caffine[i]] != INT_MAX/2) {
                dp[j] = min(dp[j], dp[j-caffine[i]]+1);
            }
            // else dp[j] = dp[j-caffine[i]];
        }
    }

    if(dp[m] == INT_MAX/2) printf("-1\n");
    else printf("%d\n", dp[m]);
}