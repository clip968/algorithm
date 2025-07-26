#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    vector<int> v(n);

    int total_weight{};
    for(int i{};i<n;++i){
        scanf("%d", &v[i]);
        total_weight += v[i];
    }

    vector<int> dp(total_weight+1, 0);
    dp[0] = 1;
    for(int i{};i<n;++i){
        int weight = v[i];
        dp[weight] = 1;
        for(int j{total_weight};j>=weight;--j){
            if(dp[j] != 0) {
                dp[j] = 1;
            } 
        }
    }

    scanf("%d", &n);
    for(int i{};i<n;++i){
        int tmp; scanf("%d", &tmp);
        if(dp[tmp] == 0) printf("N ");
        else printf("Y ");
    }


}