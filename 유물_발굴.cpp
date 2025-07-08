#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<long long, long long>&a, const pair<long long, long long>& b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int k; scanf("%d", &k);
    map<int, vector<pair<long long, long long>>> v;
    vector<pair<long long, long long>> ans;
    for(int i{1};i<=k;++i){
        long long a, x, y;
        scanf("%lld %lld %lld", &a, &x, &y);
        v[a].push_back({x, y});
    }

    for(int i{1};i<=k;++i){
        if(v[i].empty()) continue;
        long long maxx{INT_MIN/2}, minx{INT_MAX/2};
        long long maxy{INT_MIN/2}, miny{INT_MAX/2};
        for(auto k : v[i]){
            maxx = max(maxx, k.first);
            maxy = max(maxy, k.second);
            miny = min(miny, k.second);
            minx = min(minx, k.first);
        }
        long long r = (maxx - minx + 1) * (maxy - miny + 1);
        ans.push_back({r, i});
    }

    sort(ans.begin(), ans.end(), compare);

    printf("%lld %lld", ans[0].second, ans[0].first);

}