#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    vector<int> v(n);
    for(int i{};i<n;++i){
        scanf("%d", &v[i]);
    }

    stack<int> s;
    for(int i{};i<n;++i){
        while(!s.empty() && v[s.top()] < v[i]){
            v[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        v[s.top()] = -1;
        s.pop();
    }
    for(int i{};i<n;++i){
        printf("%d ", v[i]);
    }
}