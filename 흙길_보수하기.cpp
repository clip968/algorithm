#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, l;
    scanf("%d %d", &n, &l);

    vector<pair<int, int>> v(n);
    for(int i{};i<n;++i){
        scanf("%d %d", &v[i].first, &v[i].second);
    }

    sort(v.begin(), v.end());

    int pos{};
    int ans{};
    for(int i{};i<v.size();i++){
        if(pos < v[i].first) pos = v[i].first;

        while(pos < v[i].second){
            pos += l;
            ans++;
        }
    }

    printf("%d", ans);
}