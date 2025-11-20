#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; 
    while(true) {
        scanf("%d %d", &n, &m);
        
    // vector<vector<int>> v(n, vector<int>(m));
        if(n == 0 && m == 0) return 0;
        map<int, int> scores;
        for(int i{};i<n;++i){
            for(int j{};j<m;++j){
                int tmp; scanf("%d", &tmp);
                scores[tmp]++;
            }
        }

        int max_score{};
        for(auto& [number, score] : scores) {
            if(max_score < score) {
                max_score = score;
            }
        }

        int second_score{};
        for(auto& [number, score] : scores){
            if(max_score > score && second_score < score){
                second_score = score;
            }
        }

        vector<int> v;

        for(auto& [number, score] : scores) {
            if(second_score == score) {
                v.push_back(number);
            }
        }

        sort(v.begin(), v.end());

        for(auto& number : v){
            printf("%d ", number);
        }
        printf("\n");
    }
    
}