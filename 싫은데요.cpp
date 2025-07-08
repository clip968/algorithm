#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<long long> v(n);

    for(int i{};i<n;++i){
        scanf("%lld", &v[i]);
    }

    int s{}, e{};
    long long tmp{};
    long long max_tmp{};

    while(e < n){
        tmp += v[e];
        
        while(tmp > m && s <= e){
            tmp -= v[s];
            s++;
        }
        
        if(tmp <= m) max_tmp = max(max_tmp, tmp);
        e++;
        
    }
    printf("%lld", max_tmp);

}