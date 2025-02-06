#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; scanf("%d", &t);
    while(t--){
        
        int n;
        scanf("%d", &n);
        
        vector<long long> counter0(n+1, 0);
        vector<long long> counter1(n+1, 0);

        counter0[0] = 1;
        counter0[1] = 0;

        counter1[0] = 0;
        counter1[1] = 1;

        
        for(int i{2};i<=n;i++){
            counter0[i] = counter0[i-2]+counter0[i-1];
            counter1[i] = counter1[i-2]+counter1[i-1];
        }
        printf("%lld %lld\n", counter0[n], counter1[n]);
    }
}