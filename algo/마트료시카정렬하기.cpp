#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        vector<int> v;
        // priority_queue<int, vector<int>, greater<int>> pq;
        set<int> s;
        int cnt{};
        int tmp;
        for(int i{};i<n;++i){
            scanf("%d", &tmp);
            v.push_back(tmp);
            s.insert(tmp);
        }

        for(auto it=s.begin(); it!=s.end();it++){
            while(find(v.begin(), v.end(), *it) != v.end()){
                tmp = find(v.begin(), v.end(), *it) - v.begin();
                // printf("%d ", tmp);
                v.erase(v.begin() + tmp);
                cnt+=tmp;
            }
            
        }
        printf("%d\n", cnt);
    }
}