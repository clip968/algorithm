#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    long long answer = 0;
    vector<int> dice(6);
    for(int i=0;i<6;i++){
        scanf("%d", &dice[i]);
    }

    if(n == 1){
        auto maxx = max_element(dice.begin(), dice.end());
        for(auto k : dice) {
            answer += k;
        }
        answer -= *maxx;
        printf("%lld\n", answer);
        return 0;
    }
    else{
        vector<int> dice2(6);
        dice2 = dice;
        sort(dice2.begin(), dice2.end());

        long long three_way = 0;
        three_way = 200;
        vector<vector<int>> valid_combinations = {
            {0, 1, 2}, {0, 1, 3}, {0, 2, 4}, {0, 3, 4},
            {1, 2, 5}, {1, 3, 5}, {2, 4, 5}, {3, 4, 5}
        };
        
        for (auto& combo : valid_combinations) {
            long long sum = 0;
            for (int idx : combo) {
            sum += dice[idx];
            }
            three_way = min(three_way, sum);
        }

        long long two_way = 1000;
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                if(i == j) continue;
                if(i + j == 5) continue;
                two_way = min(two_way, (long long)dice[i] + dice[j]);
            }
        }

        long long one_way = 0;
        one_way = (long long)dice2[0];

        answer = (long long)(three_way * 4) + (two_way * (8 * n - 12)) + (one_way * (pow(n-2, 2) * 5 + (n-2) * 4));
        
        printf("%lld", answer);
        return 0;
    }
}