#include<bits/stdc++.h>
using namespace std;
#define JOAT 10000000

int main(){
    long long low, high;
    scanf("%lld %lld", &low, &high);

    vector<long long> v(JOAT+1);

    for(int i{2};i<=JOAT;i++){
        v[i] = i;
    }

    for(int i{2};i<=sqrt(JOAT);i++){
        if(v[i] == 0) continue;
        for(int j{2*i};j<=JOAT;j+=i){
            v[j] = 0;
        }
    }

    int cnt{};

    for(int i{2};i<=JOAT;++i){
        if(v[i] != 0){
            long long temp = v[i];
            while((double)v[i] <= (double)high / (double)temp){
                if((double)v[i] >= (double)low / (double)temp){
                    cnt++;
                }
                temp *= v[i];
            }
        }
    }

    printf("%d\n",cnt);
}