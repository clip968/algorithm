#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, c; scanf("%d %d", &c, &n);

    vector<int> dp(c+101, INT_MAX/2);
    vector<pair<int, int>> v(c); 

    for(int i{};i<n;++i){
        int cost, customer;
        scanf("%d %d", &cost, &customer);

        v[i] = {cost, customer};
    }

    dp[0] = 0;

    for(int i{1};i<=c+100;++i){
        for(int j{};j<n;++j){
            int cost = v[j].first;
            int customer = v[j].second;

            // i는 구하고자 하는 인원 수
            // 도시의 손님보다 일단 크거나 같아야 함
            if(i - customer >= 0) { 
                dp[i] = min(dp[i], dp[i-customer] + cost);
            }
        }
    }

    int result{INT_MAX/2};
    for(int i{c};i<=c+100;++i){
        result = min(result, dp[i]);
    }

    printf("%d\n", result);
}