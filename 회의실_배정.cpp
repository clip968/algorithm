#include<bits/stdc++.h>
using namespace std;
vector<pair<int ,int>> v;

int main(){
    
    int n; scanf("%d", &n);
    for(int i{};i<n;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        v.push_back({b, a});
    }

    sort(v.begin(), v.end());

    int result{};
    int prev{};
    for(auto k : v){
        if(prev <= k.second){
            prev = k.first;
            result++;
        }
    }
    printf("%d", result);

}