#include<bits/stdc++.h>
using namespace std;

int main(){
    long long low, high;
    scanf("%lld %lld", &low, &high);

    vector<bool> chk(high-low+1);

    for(long long i{2};i*i <= high;++i){
        long long pow = i * i;
        long long start = low / pow;

        if(low % pow != 0) start++;

        for(long long j{start};j * pow <= high;++j){
            chk[(int)((j*pow)-low)] = true;
        }
    }
    int cnt{};
    for(int i{};i<=high-low;++i){
        if(!chk[i]) cnt++;
    }

    printf("%d\n",cnt);
}