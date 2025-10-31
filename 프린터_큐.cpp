#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for(int i{};i<n;++i){
            int tmp{}; scanf("%d", &tmp);
            q.push({i, tmp});
            pq.push(tmp);   
        }

        int answer{};

        while(1){
            // pq의 맨 위에 있는게 가장 우선순위가 높음
            // 그러면 pq의 top 값이랑 q의 front의 second 값이랑 비교해서 top 값이 높으면 queue의 맨 뒤로 다시 넣기
            int idx{q.front().first};
            int weight{q.front().second};
            q.pop();
            // 우선순위가 가장 높은 값이랑 비교
            if(weight < pq.top()){
                q.push({idx, weight});
            }
            else{
                // 우선순위가 가장 높은 값이면 빼기
                pq.pop();
                answer++;
                if(idx == m){
                    printf("%d\n", answer);
                    break;
                }
            }
        }

    }
}