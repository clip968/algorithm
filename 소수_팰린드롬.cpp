#include<bits/stdc++.h>
using namespace std;
bool is_palindrome(long long n){
    string tmp = to_string(n);
    int s{}, e{tmp.length()-1};

    while(s < e){
        if(tmp[s] != tmp[e]) return false;
        s++;
        e--;
    }

    return true;
}


int main(){
    long long n; scanf("%lld", &n);

    vector<long long> v(2000001);
    for(int i{2};i<=2000000;++i){
        v[i]=i;
    }

    for(int i{2};i<=sqrt(2000000);++i){
        if(v[i] == 0) continue;
        for(int j{2*i};j<=2000000;j+=i){
            v[j] = 0;
        }
    }
    for(long long i{n};i<=2000000;++i){
        if(v[i] != 0 && is_palindrome(v[i])){
            printf("%lld", v[i]);
            return 0;
        } 
    }
    
}