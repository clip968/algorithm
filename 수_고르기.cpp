#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int t, m; scanf("%d %d", &t, &m);
        vector<int> v;
        // vector<pair<int, int>> result;
        int answer = 1000000001;
        for(int i{};i<t;++i){
            int tmp; scanf("%d", &tmp);
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());

        int s, e;
        s = 0, e = 1;
        while(e < v.size()){ 
            if(v[e] - v[s] >= m){
                answer = min(answer, v[e] - v[s]);
                s++;
            }
            else{
                e++;
            } 
        }
        // for(auto k : result){
        //     printf("%d %d\n", k.first, k.second);
        // }
        printf("%d\n", answer);
    }
}