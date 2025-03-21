#include<bits/stdc++.h>
using namespace std;
int dp[100005];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    vector<pair<int, int>> v;
    for(int i{};i<n;i++){
        int weight, value;
        scanf("%d%d", &weight, &value);
        v.push_back({weight, value});
    }
    for(auto m : v){
        for(int i{k};i>0;i--){
            if(i-m.first >= 0 && dp[i] < dp[i - m.first] + m.second){
                dp[i] = dp[i-m.first] + m.second;
            }
        }
    }
    // for(int i{1};i<=k;i++){
    //     printf("%d ", dp[i]);
    // }
    printf("%d\n", dp[k]);

        
}