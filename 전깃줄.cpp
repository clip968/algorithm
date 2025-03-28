#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    vector<pair<int, int>> v;

    for(int i{};i<n;i++){
        pair<int, int> tmp;
        scanf("%d %d", &tmp.first, &tmp.second);
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    vector<int> v2;
    for(int i{};i<v.size();++i){
        int tmp = v[i].second;
        auto k = lower_bound(v2.begin(), v2.end(), tmp);
        if(k == v2.end()){
            v2.push_back(tmp);
        }
        else{
            *k = tmp;
        }
    }

    printf("%d", n-v2.size());

    // for(auto k : v){
    //     printf("%d %d\n", k.first, k.second);
    // }
}