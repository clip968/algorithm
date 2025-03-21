#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> v;
    int dp[1001]={};
    int prev[1001];
    fill(dp, dp+1001, 0);
    fill(prev, prev+1001, -1);
    v.push_back(0);
    for(int i{};i<n;++i){
        int tmp; scanf("%d", &tmp);
        v.push_back(tmp);
    }
    int max_dp{}, max_idx{};
    for(int i{1};i<=n;++i){
        for(int j=i-1; j>=0; --j){
            if(dp[i]<dp[j]+1 && v[i] > v[j]){
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if(max_dp < dp[i]){
            max_dp = dp[i];
            max_idx = i; 
        } 
    }
    // int cnt{1};
    // printf("%d\n", dp[n]);

    vector<int> answer;
    for(int i=max_idx;i!=-1;i=prev[i]){
        if(i > 0){
            answer.push_back(v[i]);
        }
    }
    printf("%d\n", max_dp);
    for(int i=answer.size()-1;i>=0;--i) {
        printf("%d ", answer[i]);
    } 
   


}