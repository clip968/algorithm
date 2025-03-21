#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(n);
    vector<int> answer;
    for(int i{};i<n;++i){
        scanf("%d", &v[i]);
    }
    vector<int> prefix(n+1, 0);
    for(int i{};i<n;++i){
        prefix[i+1] = prefix[i] ^ v[i];
    }

    int result{};
    for(int i{};i<m;++i){
        int s, e;
        scanf("%d %d", &s, &e);

        s--, e--;

        int tmp = prefix[e+1] ^ prefix[s];
        result ^= tmp;
    }

    printf("%d", result);
}