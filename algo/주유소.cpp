#include<bits/stdc++.h>
using namespace std;
vector<long long> dist;
vector<long long> oil;

int main(){
    int n; scanf("%d", &n);
    long long temp, rangeSum=0;
    for(int i=0;i<n-1;i++){
        scanf("%lld", &temp);
        dist.push_back(temp);
        rangeSum += temp;
    }
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        oil.push_back(temp);
    }
    long long ans = oil[0] * dist[0];
    temp = oil[0];
    for(int i=1;i<n-1;i++){
        temp = min(temp, oil[i]);
        ans += dist[i] * temp;
    }

    printf("%lld", ans);
    
}