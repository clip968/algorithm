#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> v(m+1);

    for(int i{2};i<=m;++i){
        v[i] = i;
    }

    for(int i{2}; i<=sqrt(m);++i){
        if(v[i] == 0) continue;
        for(int j{2*i};j<=m;j+=i){
            v[j] = 0;
        }
    }

    for(int i{n};i<=m;++i){
        if(v[i] != 0) printf("%d\n", v[i]);
    }
}